#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include <complex>

#include "SDL.hpp"
#include "Point.hpp"
#include "Window.hpp"
#include "Renderer.hpp"

typedef std::complex<double> Complex;

class Mandelbrot
{
public:

  explicit Mandelbrot(SDL::Window& window, Complex origin, double zoom, unsigned maxIteration);

  virtual ~Mandelbrot();


  double getZoom() const;

  double getEpsilon() const;

  Complex getCenter() const;

  unsigned getWidth() const;

  unsigned getHeight() const;

  Mandelbrot& renderImage();
  
protected:

  double iterate(Complex c) const;

  Mandelbrot& zoomIn(unsigned factor);

  Mandelbrot& moveFrom(Complex c);

  Mandelbrot& moveTo(Complex c);

  Complex screenToCartesian(unsigned x, unsigned y) const;  

  Mandelbrot& renderPixel(unsigned x, unsigned y, Uint32 color);


private:

  SDL::Renderer m_renderer;

  double m_zoom;
 
  Complex m_center;

  unsigned m_width;

  unsigned m_height;

  unsigned m_maxIteration;

};


#endif // MANDELBROT_HPP
