#pragma once
#include <cstdint>
#include <string>

namespace MathClasses
{
    using Byte = unsigned char;

    struct Colour
    {
        std::uint32_t colour; 

        Colour();

        Colour(Byte red, Byte green, Byte blue, Byte alpha);

        Byte GetRed() const;
        void SetRed(Byte red);

        Byte GetGreen() const;
        void SetGreen(Byte green);

        Byte GetBlue() const;
        void SetBlue(Byte blue);

        Byte GetAlpha() const;
        void SetAlpha(Byte alpha);

        friend bool operator==(Colour a, Colour b);
        friend bool operator!=(Colour a, Colour b);

        std::string ToString() const;
        void RedToGreen(Byte red);
    };
}