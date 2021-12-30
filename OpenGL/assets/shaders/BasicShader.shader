#shader vertex
#version 300 es
precision mediump float;
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord ;
out vec3 ourColor;
out vec2 texCoord;
uniform mat4 transform;
void main()
{
    gl_Position = transform * vec4(aPos, 1.0);
    ourColor = aColor;
    texCoord = aTexCoord;
}

#shader fragment    
#version 300 es
precision mediump float;
out vec4 FragColor;

in vec3 ourColor;
in vec2 texCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, texCoord) * vec4(ourColor, 1.0);
}
