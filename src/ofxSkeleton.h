//
//     _____    ___
//    /    /   /  /     ofxSkeleton
//   /  __/ * /  /__    (c) ponies & light, 2012, 2013. All rights reserved.
//  /__/     /_____/    poniesandlight.co.uk
//
//  ofxSkeleton.h
//  Created by tim on 12/11/2012.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include "ofMain.h"

namespace pal {
	namespace ofxSkeleton {
		
		
		// a bone is what links two joints.
		// a joint is linked to its parent joint through a bone.
		
		// a joint that has no parents is a root joint.
		
		class ofxJoint {
			
		private:
			
			weak_ptr<ofxJoint>					parent;
			ofMatrix4x4							localTransformMatrix;
			ofMatrix4x4							localParentTransformMatrix;
			
			virtual void						customDraw(float r);
			
		public:
			
			void								setTransformMatrix(ofMatrix4x4 m_);
			void								setOrientation(ofQuaternion orientation_);
			void								setOrientationAtParent(ofQuaternion orientation_);
			
			void								setPosition(ofVec3f position_);
			void								setGlobalOrientation(ofQuaternion orientation_);
			void								setGlobalOrientationAtParent(ofQuaternion orientation_);
			
			void								setGlobalPosition(ofVec3f position_);
			void								setParent(shared_ptr<ofxJoint> parent_);
			
			void								draw(float r_ = 4.0);
			void								drawAxes();
			
			shared_ptr<ofxJoint>				getParent();
			
			const ofQuaternion					getOrientation()				const;
			const ofQuaternion					getOrientationAtParent()		const;
			const ofMatrix4x4					getLocalTransformMatrix()		const;
			const ofMatrix4x4					getParentTransformMatrix()		const;
			const ofVec3f						getParentPosition()				const;
			
			const ofMatrix4x4					getGlobalTransformMatrix()		const;
			const ofMatrix4x4					getGlobalParentTransformMatrix()const;
			
			const ofQuaternion					getGlobalOrientationAtParent()	const;
			const ofQuaternion					getGlobalOrientation()			const;
			const ofVec3f						getGlobalPosition()				const;
			const ofVec3f						getGlobalParentPosition()		const;
			
			ofxJoint()
			:parent()	// will automatically initialize as a NULL shared ptr.
			{};
			
		};
		
		// --------------------------------------------------------
		// this is currently only in prototype stage:
		
		class ofxIKchain {
		public:
			vector<shared_ptr<ofxJoint> >		bones;
			shared_ptr<ofxJoint>				endEffector;
			ofVec3f								targetPositionInGlobalSpace;
			
			void								solve();
		};
		
	}	// namespace ofxSkeleton
}	// namespace pal
