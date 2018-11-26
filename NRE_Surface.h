
    /// \file NRE_Surface.h
    /// \brief Declaration of Engine's Texture : Surface
    /// \author Louis ABEL
    /// \version 0.1

    #pragma once

    #include <cstring>
    #include <GL/glew.h>
    #include <SDL2/SDL_image.h>
    #include "../Font/NRE_Font.h"
    #include "../../../Math/Vector/NRE_Vector.h"
    #include "../../../ErrorHandler/NRE_ErrorHandler.h"

    const std::string NRE_SURFACE_PATH_DEFAULT = "";

    /// \class NRE_Surface
    /// \brief Support for Engine's texture
    /// Derived from an SDL_Surface
    class NRE_Surface
    {
        private :
            SDL_Surface *surface;
            NRE_Vector2D<GLushort> size;
            GLenum internalFormat;
            GLenum format;
            std::string path;
            bool loaded;

        public :
            /// \brief Constructor
            /// Set the default loaded state, and the path
            NRE_Surface(std::string const& path = NRE_SURFACE_PATH_DEFAULT);
            /// \brief De-Constructor
            /// Free the surface memory
            ~NRE_Surface();
            /// \brief Surface's Address setter
            /// Set the address of the pointed SDL_Surface to s
            /// \param s : Pointer on SDL_Surface, new address for the surface
            void set_Surface(SDL_Surface *s);
            /// \brief Size's setter
            /// Set the size's value to size
            /// \param size : NRE_Vector2D<GLushort>, the new surface's size, not modified
            void set_Size(NRE_Vector2D<GLushort> const& size);
            /// \brief InternalFormat's setter
            /// Set the internalFormat's value to f
            /// \param f : GLenum, new internalFormat's value, not modified
            void set_InternalFormat(GLenum const& f);
            /// \brief Format's setter
            /// Set the format's value to f
            /// \param f : GLenum, new format's value, not modified
            void set_Format(GLenum const& f);
            /// \brief Path's setter
            /// Set the path's value to path
            /// \param path : std::string, new path's value, not modified
            void set_Path(std::string const& path);
            /// \brief Loaded's setter
            /// Set the loaded's state to state
            /// \param state : Boolean, new loaded's state, not modified
            void set_Loaded(bool const& state);
            /// \brief Surface's getter
            /// Return the surface's address
            /// \return Pointer on SDL_Surface, modifiable
            SDL_Surface* get_Surface();
            /// \brief Size's getter
            /// Return the size's value
            /// \return NRE_Vector2D<GLushort>, the size's reference, not modifiable
            const NRE_Vector2D<GLushort> get_Size() const;
            /// \brief InternalFormat's getter
            /// Return the internalFormat's value
            /// \return GLenum, internalFormat's reference, not modifiable
            const GLenum& get_InternalFormat() const;
            /// \brief Format's getter
            /// Return the format's value
            /// \return GLenum, format's reference, not modifiable
            const GLenum& get_Format() const;
            /// \brief Path's getter
            /// Return the path's value
            /// \return std::string, path's reference, not modifiable
            const std::string& get_Path() const;
            /// \brief Loaded's getter
            /// Return the loaded's state
            /// \return Boolean, loaded's reference, not modifiable
            const bool& get_Loaded() const;

            /// \brief Load the surface from an image, with IMG_Load
            /// Load an image with IMG_Load, flip it and find the pixel's format
            void load_ByIMG();
            /// \brief Load the surface from a text, with TTF_RenderText_Solid
            /// Load a a text (stored in path attribute) with TTF_RenderText_Solid, flip it and store the given pixel's format
            /// \param font : NRE_Font, the font use for text rendering
            void load_ByTTF(NRE_Font const& font);
            /// \brief Flip the surface data to get an OpenGL's compatible surface
            /// Use a temporary surface and use memcpy to flip the pixel's data
            void flip();
            /// \brief Free the surface memory
            /// Free the surface memory, keep the same path
            void free();
    };
