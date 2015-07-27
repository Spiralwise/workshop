#version 330 core
layout(location = 0) in vec3 vertex_position;
uniform mat4 TransformMat;

void main() {
    vec4 v = vec4(vertex_position, 1);
    gl_Position = TransformMat * v;
}