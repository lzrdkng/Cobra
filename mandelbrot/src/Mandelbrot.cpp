#include "Mandelbrot.hpp"

#include <cmath>

const log2 = std::log(2);

Mandelbrot::Mandelbrot(SDL::Window& window, Complex origin, double zoom, unsigned maxIteration)
: m_renderer(window, SDL::RenderAccelerated),
  m_zoom(zoom),
  m_center(origin),
  m_width(window.getWidth()),
  m_height(window.getHeight()),
  m_maxIteration (maxIteration)
{

}

Mandelbrot::~Mandelbrot()
{

}


double Mandelbrot::getZoom() const
{
  return m_zoom;
}

double Mandelbrot::getEpsilon() const
{
  if (m_zoom == 0)
    return -1;
  return 1/m_zoom;
}

Complex Mandelbrot::getCenter() const
{
  return m_center;
}

unsigned Mandelbrot::getWidth() const
{
  return m_width;
}

unsigned Mandelbrot::getHeight() const
{
  return m_height;
}

double Mandelbrot::iterate(Complex c) const
{
  Complex z(c);

  unsigned i(0);

  while (std::abs(z) <= 2 && i < m_maxIteration)
  {
    z = z*z + c;
    ++i;
  }

  if (i == 0)
    return -1;

  return i + 1 - std::log(std::log(std::abs(z)))/log2;
}

Mandelbrot& Mandelbrot::zoomIn(unsigned factor)
{
  if (factor > 1)
    m_zoom *= factor;
  return *this;
}

Mandelbrot& Mandelbrot::moveFrom(Complex c)
{
  m_center += c;
  return *this;
}

Mandelbrot& Mandelbrot::moveTo(Complex c)
{
  m_center = c;
  return *this;
}

Complex Mandelbrot::screenToCartesian(unsigned x, unsigned y) const
{
  Complex screenPosition(x - m_width/2 , m_height/2 - y);
  screenPosition += m_zoom * m_center;
  screenPosition *= this->getEpsilon();
  return screenPosition;
}

Mandelbrot& Mandelbrot::renderPixel(unsigned x, unsigned y, Uint32 color)
{
  m_renderer.setDrawColor(color).drawPixel(x, y); // setDrawColor not defined 
}

Mandelbrot& Mandelbrot::renderImage()
{
  for (unsigned x=0; x<m_width; ++x)
  {
    for (unsigned y=0; y<m_height; ++y)
    {
      this->renderPixel(x, y, iterate(screenToCartesian(x, y));
    }
  }

  m_renderer.clear();
  m_renderer.present();
}

