//
//  VertexBufferElement.h
//  OpenGL
//
//  Created by Ayush Anshul on 24/12/21.
//

#ifndef VertexBufferElement_hpp
#define VertexBufferElement_hpp

#include "Renderer.hpp"

struct VertexBufferElement{
    unsigned int type;
    unsigned int count;
    unsigned int normalised;
    
    static unsigned int GetSizeOfType(unsigned int type){
        switch(type){
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_BYTE:           return 1;
              
        }
        ASSERT(false);
        return 0;
    }
};

#endif /* VertexBufferElement_h */
