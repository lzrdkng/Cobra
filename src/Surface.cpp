#include "Surface.hpp"

using namespace SDL;


Surface::Surface(SDL_Surface* surface) : m_surface(surface)
{

}

Surface::~Surface()
{
    if (m_surface != nullptr)
        SDL_FreeSurface(m_surface);
        m_surface = nullptr;
}

Rect Surface::getClipRect() const
{
    return Rect::fromSDL(m_surface->clip_rect);
}
/*
PixelFormat Surface::getFormat() const
{
    return (PixelFormats)(*(m_surface->format));
}*/

int Surface::getPitch() const
{
    return m_surface->pitch;
}

std::pair<int, int> Surface::getSize() const
{
    std::pair<int, int> size(m_surface->w, m_surface->h);
    return size;
}

Surface& Surface::blit(const Rect& srcRect, Surface &dst, Rect &dstRect)
{
    if (SDL_BlitSurface(m_surface, srcRect.toSDL(), dst.toSDL(), dstRect.toSDL()) != 0)
        throw Error(SDL_GetError());
    return *this;
}

Surface& Surface::blit(Surface &dst, Rect &dstRect)
{
    if (SDL_BlitSurface(m_surface, NULL, dst.toSDL(), dstRect.toSDL()) != 0)
        throw Error(SDL_GetError());
    return *this;
}

Surface& Surface::fillRect(const Rect& rect, Uint32 color)
{
    if (SDL_FillRect(m_surface, rect.toSDL(), color) != 0)
        throw Error(SDL_GetError());
    return *this;
}

Surface& Surface::fillRect(Uint32 color)
{
    if (SDL_FillRect(m_surface, NULL, color) != 0)
        throw Error(SDL_GetError());
    return *this;
}

const SDL_Surface* Surface::toSDL() const
{
    return m_surface;
}

SDL_Surface* Surface::toSDL()
{
    return m_surface;
}
