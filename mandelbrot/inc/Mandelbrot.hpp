#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include <complex>

#include "SDL.hpp"
#include "Point.hpp"
#include "Window.hpp"
#include "Renderer.hpp"

typedef std::complex<long double> Complex;

class Mandelbrot
{
public:

  explicit Mandelbrot(SDL::Window& window, Complex origin, double zoom, unsigned maxIteration);

  virtual ~Mandelbrot();


  long double getZoom() const;

  long double getEpsilon() const;

  Complex getCenter() const;

  double getWidth() const;

  double getHeight() const;

  Mandelbrot& renderImage();
  
  Mandelbrot& zoomIn(long double factor);

  Mandelbrot& moveFrom(Complex c);

  Mandelbrot& moveTo(Complex c);

protected:

  long double iterate(Complex c) const;

  Complex screenToCartesian(unsigned x, unsigned y) const;

  Mandelbrot& renderPixel(unsigned x, unsigned y, long double color);


private:

  SDL::Renderer m_renderer;

  SDL_PixelFormat* m_format;

  long double m_zoom;
 
  Complex m_center;

  double m_width;

  double m_height;

  unsigned m_maxIteration;

};


#endif // MANDELBROT_HPP
