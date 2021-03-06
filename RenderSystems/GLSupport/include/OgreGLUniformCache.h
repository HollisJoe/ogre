/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2014 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef __GLUniformCache_H__
#define __GLUniformCache_H__

#include "OgreGLSupportPrerequisites.h"

typedef Ogre::GeneralAllocatedObject UniformCacheAlloc;

namespace Ogre
{
    /** An in memory cache of the OpenGL uniforms. */
    class _OgreGLExport GLUniformCache : public UniformCacheAlloc
    {
    protected:
        typedef OGRE_HashMap<int, uint32> UniformMap;

        /// A map of uniform names and a hash of their values
        UniformMap mUniformValueMap;

    public:
        /** Clears all cached values
        */
        void clearCache();
        
        /** Update a uniform
         @return A boolean value indicating whether this uniform needs to be updated in the GL.
         */
        bool updateUniform(int location, const void *value, int length);
    };
}

#endif
