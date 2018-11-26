
    #include "NRE_Surface.h"

    NRE_Surface::NRE_Surface(std::string const& path) : surface(0), internalFormat(0), format(0), path(path), loaded(false)
    {
    }

    NRE_Surface::~NRE_Surface()
    {
        if (get_Loaded())
        {
            free();
        }
    }

    void NRE_Surface::set_Surface(SDL_Surface *s)
    {
        surface = s;
    }

    void NRE_Surface::set_Size(NRE_Vector2D<GLushort> const& size)
    {
        this->size = size;
    }

    void NRE_Surface::set_InternalFormat(GLenum const& f)
    {
        internalFormat = f;
    }

    void NRE_Surface::set_Format(GLenum const& f)
    {
        format = f;
    }

    void NRE_Surface::set_Path(std::string const& path)
    {
        this->path = path;
    }

    void NRE_Surface::set_Loaded(bool const& state)
    {
        loaded = state;
    }

    SDL_Surface* NRE_Surface::get_Surface()
    {
        return surface;
    }

    const NRE_Vector2D<GLushort> NRE_Surface::get_Size() const
    {
        return size;
    }

    const GLenum& NRE_Surface::get_InternalFormat() const
    {
        return internalFormat;
    }

    const GLenum& NRE_Surface::get_Format() const
    {
        return format;
    }

    const std::string& NRE_Surface::get_Path() const
    {
        return path;
    }

    const bool& NRE_Surface::get_Loaded() const
    {
        return loaded;
    }

    void NRE_Surface::load_ByIMG()
    {
        try
        {
            SDL_Surface* sdlSurface = IMG_Load(get_Path().c_str());
            set_Surface(sdlSurface);

            if (get_Surface() == 0)
            {
                throw (NRE_Error(NRE_ERRORLEVEL_CRITICAL_MEMORY_ALLOCATION_ERROR, NRE_ERRORCODE_NO_MEMORY_ALLOCATED, "Surface : " + get_Path() + " cannot be loaded"));
            }

            flip();

            if (get_Surface()->format->BytesPerPixel == 3)
            {
                set_InternalFormat(GL_RGB);
                if (get_Surface()->format->Rmask == 0xFF)
                {
                    set_Format(GL_RGB);
                }
                else
                {
                    set_Format(GL_BGR);
                }
            }
            else if (get_Surface()->format->BytesPerPixel == 4)
            {
                set_InternalFormat(GL_RGBA);
                if (get_Surface()->format->Rmask == 0xFF)
                {
                    set_Format(GL_RGBA);
                }
                else
                {
                    set_Format(GL_BGRA);
                }
            }
            else
            {
                SDL_FreeSurface(get_Surface());
                throw (NRE_Error(NRE_ERRORLEVEL_CRITICAL_FILE_ERROR, NRE_ERRORCODE_UNSUPPORTED_FORMAT, "Surface : " + get_Path() + " Img format not supported"));
            }
            set_Size(NRE_Vector2D<GLushort>(get_Surface()->w, get_Surface()->h));

            set_Loaded(true);
        }
        catch (NRE_Error const& e)
        {
            throw e;
        }
        catch(std::exception const& e)
        {
            throw e;
        }
    }

    void NRE_Surface::load_ByTTF(NRE_Font const& font)
    {
        try
        {
            SDL_Surface* tmpTTF = TTF_RenderText_Solid(font.get_Font(), get_Path().c_str(), font.get_Color());

            if (tmpTTF == 0)
            {
                throw (NRE_Error(NRE_ERRORLEVEL_CRITICAL_MEMORY_ALLOCATION_ERROR, NRE_ERRORCODE_NO_MEMORY_ALLOCATED, "Surface : " + get_Path() + " cannot be loaded"));
            }

            SDL_PixelFormat *pixelFormat = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
            SDL_Surface* sdlSurface = SDL_ConvertSurface(tmpTTF, pixelFormat, 0);
            SDL_FreeSurface(tmpTTF);
            if (sdlSurface == 0)
            {
                SDL_FreeFormat(pixelFormat);
                throw (NRE_Error(NRE_ERRORLEVEL_CRITICAL_MEMORY_ALLOCATION_ERROR, NRE_ERRORCODE_NO_MEMORY_ALLOCATED, "Surface : " + get_Path() + " cannot be loaded"));
            }

            set_Surface(sdlSurface);
            flip();

            set_InternalFormat(GL_RGBA);
            set_Format(GL_RGBA);

            SDL_FreeFormat(pixelFormat);
            set_Size(NRE_Vector2D<GLushort>(get_Surface()->w, get_Surface()->h));

            set_Loaded(true);
        }
        catch (NRE_Error const& e)
        {
            throw e;
        }
        catch(std::exception const& e)
        {
            throw e;
        }
    }

    void NRE_Surface::flip()
    {
        int pitch;
        SDL_Surface *flipedSurface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                       get_Surface()->w,get_Surface()->h,
                                       get_Surface()->format->BitsPerPixel,
                                       get_Surface()->format->Rmask,
                                       get_Surface()->format->Gmask,
                                       get_Surface()->format->Bmask,
                                       get_Surface()->format->Amask);

        SDL_LockSurface(get_Surface());
        SDL_LockSurface(flipedSurface);

        pitch = get_Surface()->pitch;
        for (unsigned int currentLine = 0; currentLine < static_cast <unsigned int> (get_Surface()->h); currentLine = currentLine + 1)
        {
            memcpy(&((unsigned char* )flipedSurface->pixels)[currentLine * pitch],
                   &((unsigned char* )get_Surface()->pixels)[(get_Surface()->h - 1 - currentLine) * pitch],
                   pitch);
        }

        SDL_UnlockSurface(flipedSurface);
        SDL_UnlockSurface(get_Surface());
        SDL_FreeSurface(get_Surface());
        set_Surface(flipedSurface);
    }

    void NRE_Surface::free()
    {
        if (get_Surface() != 0)
        {
            SDL_FreeSurface(get_Surface());
            set_Surface(0);
        }
        set_Loaded(false);
    }
