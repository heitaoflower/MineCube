//
//  Cube.hpp
//
//  Created by 吴博文 on 2018/5/21.
//  Copyright © 2018年 吴博文. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include "Global.hpp"
#include "GLBufferManager.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <string>
#include <numeric>
#include <memory>
using std::shared_ptr;
using std::vector;
using std::string;

/**
 * This is a base class for cube.
 * You can inherit it and create your own cube.
 */
class Cube {
    private:
        static const unsigned int COOR_DIMENSION = 3;
        static const unsigned int NOR_VECTOR_DIMENSION = 3;
        static const unsigned int COLOR_DIMENSION = 3;
        static const unsigned int VERTEX_PER_CUBE = 36;
        static const unsigned int VERTEX_PER_PLANE = 6;
        static const vector<GLfloat> cubeVertex;
        static const vector<GLfloat> cubeNormal;
        static const vector<GLfloat> initCubeColor;

        static const unsigned int POSITION_ATTRI_OFFSET = 0;
        static const unsigned int NOR_VECTOR_ATTRI_OFFSET = 3;
        static const unsigned int COLOR_ATTRI_OFFSET = 6;


        glm::mat4 model;
        string modelMat4Name;
        GLuint shaderID;
        glm::vec4 cubeColor;

        void useModelMat4();

    public:
        Cube(
            GLfloat size,
            GLuint shaderID,
            string mat4Name,
            vector<GLuint> attriSize
        );
        Cube(const Cube &) = delete;
        ~Cube();

        virtual void editColor(
            GLfloat r,
            GLfloat g,
            GLfloat b,
            GLfloat alpha=1.0
        );

        virtual void setModelMat4(const glm::mat4 &);

        virtual void setShaderId(const GLuint & shaderID);

        virtual glm::vec3 getColor();
        virtual glm::vec3 getColorOfPLane(unsigned int plane);
};



#endif /* Cube_hpp */
