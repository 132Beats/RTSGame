//
// Created by hendrik on 17.10.19.
//

#ifndef RTS_TEXTURE_H
#define RTS_TEXTURE_H


#include <string>

class Texture {
private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    unsigned char* m_LocalBuffer;
    int m_Width, m_Height, m_BPP;

public:
    Texture(const std::string& path);

    Texture(const std::string &mFilePath);

    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;
};


#endif //RTS_TEXTURE_H
