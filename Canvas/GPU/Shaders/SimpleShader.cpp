#include "SimpleShader.h"
#include "my_math.h"

void SimpleShader::fragment(Pixels & pixels)
{
    for (auto &pixel : pixels) {
        this->fragment(pixel);
    }
}

void SimpleShader::fragment(Pixel &pixel)
{
    pixel._color = sample(TextureGenerator::get()->textureAt(texture_unit), pixel.uv());
}
