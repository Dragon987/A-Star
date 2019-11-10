#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

sf::RectangleShape get_shape(int i, int j, int scale, const sf::Color& col=sf::Color::White)
{
  sf::RectangleShape r({ static_cast<float>(scale), static_cast<float>(scale) });

  r.setPosition({ static_cast<float>(i * scale), static_cast<float>(j * scale) });

  r.setFillColor(col);
  r.setOutlineThickness(1.f);
  r.setOutlineColor(sf::Color::Black);

  return r;
}

int width = 600, height = 600, scale = 10;  
int rows = height / scale;
int cols = width / scale;

struct vec2
{
  int i, j;
  bool is_wall;
  vec2() : i(0), j(0), is_wall(false) {}
  vec2(int i, int j, bool w = false) : i(i), j(j), is_wall(w) {}
  vec2(const vec2& other) = default;
  vec2& operator=(const vec2& other) = default;
  operator int()
  {
    return j * cols + i;
  }
  operator bool()
  {
    return is_wall;
  }
};

float dist(const vec2& n, const vec2& e)
{
  return std::sqrt(std::pow(std::abs(e.i - n.i), 2) + std::pow(std::abs(e.j - n.j), 2));  
}

float heuristics(const vec2& n, const vec2& e)
{
  return dist(n, e);  
}


bool operator==(const vec2& f, const vec2& s)
{
  if ((f.i == s.i) && (f.j == s.j))
    return 1;
  return 0;
}

bool operator!=(const vec2& f, const vec2& s)
{
  return !(f == s);
}

template <class T>
bool find(std::vector<T> v, const T& e)
{
  for (std::size_t i = 0; i < v.size(); ++i)
    if (e == v[i])
      return 1;
  return 0;
}

template<typename T1, typename T2>
std::vector<vec2> rec_path(T1& cf, T2& curr)
{
  std::vector<vec2> tp;
  while (cf.find(curr) != cf.end())
  {
    curr = cf[curr];
    tp.insert(tp.begin(), curr);
  }    
  return tp;
}


int main()
{
  std::srand(std::time(0));
  sf::RenderWindow window(sf::VideoMode(width, height), "A*");

  std::vector<vec2> cells;
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j)
      cells.push_back(vec2(i, j, (float)rand() / (float)RAND_MAX < .38f ? true : false));

  vec2& start = cells[0];
  vec2& end = *(cells.end() - 1);

  start.is_wall = false;
  end.is_wall = false;
  //(cells.end() - 1)->is_wall = false;
  
  std::vector<vec2> open_set, fp;
  open_set.push_back(start);
 
  std::map<int, float>
           f_score, g_score;
  std::map<int, vec2> came_from;
  
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j)
      {
        f_score[j * cols + i] = INFINITY;
        g_score[j * cols + i] = INFINITY;
      }
 
  f_score[0] = heuristics(start, end);
  g_score[0] = 0;
  bool done = false, rp = false;
  
  while(window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    if (!done)
    {
      vec2 current = open_set[0];
      for (auto i = 1UL; i < open_set.size(); ++i)
        if (f_score[open_set[i]] < f_score[current])
          current = open_set[i];

      if (current == end)
      {
        done = true;
        rp = true;
        fp = rec_path(came_from, current);
        continue;
      }

      if (open_set.empty())
      {
        done = true;
        continue;
      }
    
      auto curr_iter_open = std::find(std::begin(open_set), std::end(open_set), current);
      if (curr_iter_open != std::end(open_set))
        open_set.erase(curr_iter_open);
    
      std::vector<vec2> neighbors;

      if (current.i - 1 >= 0 && !cells[current.i - 1 + (current.j) * cols])
        neighbors.push_back(vec2(current.i - 1, current.j));

      if (current.i + 1 < cols && !cells[current.i + 1 + (current.j) * cols])
        neighbors.push_back(vec2(current.i + 1, current.j));

      if (current.j - 1 >= 0 && !cells[current.i + (current.j - 1) * cols])
        neighbors.push_back(vec2(current.i, current.j - 1));

      if (current.j + 1 < rows && !cells[current.i + (current.j + 1) * cols])
        neighbors.push_back(vec2(current.i, current.j + 1));

      for (std::size_t i = 0; i < neighbors.size(); ++i)
      {
        float tg = g_score[current] + dist(current, neighbors[i]);
        if (tg < g_score[neighbors[i]])
        {
          came_from[neighbors[i]] = current;
          g_score[neighbors[i]] = tg;
          f_score[neighbors[i]] = tg + heuristics(neighbors[i], end );
          if (std::find(open_set.begin(), open_set.end(), neighbors[i]) == open_set.end())
            open_set.push_back(neighbors[i]);
        }
      }
    
      window.clear(sf::Color::White);
   
      for (int i = 0; i < cols; ++i)
        for (int j = 0; j < rows; ++j)
        {
          if (cells[j * cols + i])
          {
            window.draw(get_shape(i, j, scale, sf::Color::Black));
            continue;
          }
          window.draw(get_shape(i, j, scale,
                                (std::find(std::begin(open_set), std::end(open_set), vec2(i, j)) != std::end(open_set))
                                ? sf::Color::Blue : sf::Color::White));
        }
      window.draw(get_shape(current.i, current.j, scale, sf::Color::Green));
    
      window.display();
    }
    else
    {
      if (rp)
      {
        window.clear(sf::Color::White);
        for (int i = 0; i < cols; ++i)
          for (int j = 0; j < rows; ++j)
            window.draw(get_shape(i, j, scale, cells[j * cols + i] ? sf::Color::Black : sf::Color::White));
        fp.push_back(end);
        for (vec2& v : fp)
          window.draw(get_shape(v.i, v.j, scale, sf::Color::Yellow));
        
        window.display();
      }
    }
  }    

}
