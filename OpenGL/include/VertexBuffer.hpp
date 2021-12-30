//
//  VertexBuffer.hpp
//  OpenGL
//
//  Created by Ayush Anshul on 24/12/21.
//

#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

class VertexBuffer{
private:
    unsigned int m_RendererId;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();
    
    void Bind() const;
    void UnBind() const;
};


#endif /* VertexBuffer_hpp */
