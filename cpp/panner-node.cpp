#include <cstdlib>
#include <iostream>

#include "panner-node.hpp"

using namespace v8;
using namespace node;
using namespace std;


#define THIS_PANNER_NODE                                                    \
	PannerNode *pannerNode = ObjectWrap::Unwrap<PannerNode>(info.This());

#define THIS_CHECK                                                            \
	if (pannerNode->_isDestroyed) return;

#define DES_CHECK                                                             \
	if (_isDestroyed) return;

#define CACHE_CAS(CACHE, V)                                                   \
	if (pannerNode->CACHE == V) {                                           \
		return;                                                               \
	}                                                                         \
	pannerNode->CACHE = V;


Nan::Persistent<v8::Function> PannerNode::_constructor;


void PannerNode::init(Local<Object> target) {
	
	Local<FunctionTemplate> proto = Nan::New<FunctionTemplate>(newCtor);
	
	proto->InstanceTemplate()->SetInternalFieldCount(1);
	proto->SetClassName(JS_STR("PannerNode"));
	
	
	// Accessors
	Local<ObjectTemplate> obj = proto->PrototypeTemplate();
	ACCESSOR_R(obj, isDestroyed);
	
	
	// -------- dynamic
	
	
	
	Nan::SetPrototypeMethod(proto, "destroy", destroy);
	
	
	// -------- static
	
	Local<Function> ctor = Nan::GetFunction(proto).ToLocalChecked();
	
	
	
	
	_constructor.Reset(ctor);
	Nan::Set(target, JS_STR("PannerNode"), ctor);
	
	
}


NAN_METHOD(PannerNode::newCtor) {
	
	CTOR_CHECK("PannerNode");
	
	PannerNode *pannerNode = new PannerNode();
	pannerNode->Wrap(info.This());
	
	RET_VALUE(info.This());
	
}


PannerNode::PannerNode() {
	
	_isDestroyed = false;
	
}


PannerNode::~PannerNode() {
	
	_destroy();
	
}


void PannerNode::_destroy() { DES_CHECK;
	
	_isDestroyed = true;
	
	
	
}



NAN_METHOD(PannerNode::destroy) { THIS_PANNER_NODE; THIS_CHECK;
	
	pannerNode->_destroy();
	
}


NAN_METHOD(PannerNode::setPosition) { THIS_PANNER_NODE; THIS_CHECK;
	
	REQ_FLOAT_ARG(0, x);
	REQ_FLOAT_ARG(1, y);
	REQ_FLOAT_ARG(2, z);
	
	// TODO: do something?
	
}


NAN_METHOD(PannerNode::setOrientation) { THIS_PANNER_NODE; THIS_CHECK;
	
	REQ_FLOAT_ARG(0, x);
	REQ_FLOAT_ARG(1, y);
	REQ_FLOAT_ARG(2, z);
	
	// TODO: do something?
	
}



NAN_GETTER(PannerNode::isDestroyedGetter) { THIS_PANNER_NODE;
	
	RET_VALUE(JS_BOOL(pannerNode->_isDestroyed));
	
}


NAN_GETTER(PannerNode::panningModelGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_UTF8(pannerNode->_panningModel));
	
}

NAN_SETTER(PannerNode::panningModelSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_UTF8_ARG;
	
	if (pannerNode->_panningModel == *v) {
		return;
	}
	pannerNode->_panningModel = *v;
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::positionXGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(pannerNode->_positionX));
	
}

NAN_SETTER(PannerNode::positionXSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_OBJ_ARG;
	
	if (Nan::New(pannerNode->_positionX) == v) {
		return;
	}
	pannerNode->_positionX.Reset(v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::positionYGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(pannerNode->_positionY));
	
}

NAN_SETTER(PannerNode::positionYSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_OBJ_ARG;
	
	if (Nan::New(pannerNode->_positionY) == v) {
		return;
	}
	pannerNode->_positionY.Reset(v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::positionZGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(pannerNode->_positionZ));
	
}

NAN_SETTER(PannerNode::positionZSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_OBJ_ARG;
	
	if (Nan::New(pannerNode->_positionZ) == v) {
		return;
	}
	pannerNode->_positionZ.Reset(v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::orientationXGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(pannerNode->_orientationX));
	
}

NAN_SETTER(PannerNode::orientationXSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_OBJ_ARG;
	
	if (Nan::New(pannerNode->_orientationX) == v) {
		return;
	}
	pannerNode->_orientationX.Reset(v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::orientationYGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(pannerNode->_orientationY));
	
}

NAN_SETTER(PannerNode::orientationYSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_OBJ_ARG;
	
	if (Nan::New(pannerNode->_orientationY) == v) {
		return;
	}
	pannerNode->_orientationY.Reset(v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::orientationZGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(pannerNode->_orientationZ));
	
}

NAN_SETTER(PannerNode::orientationZSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_OBJ_ARG;
	
	if (Nan::New(pannerNode->_orientationZ) == v) {
		return;
	}
	pannerNode->_orientationZ.Reset(v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::distanceModelGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_UTF8(pannerNode->_distanceModel));
	
}

NAN_SETTER(PannerNode::distanceModelSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_UTF8_ARG;
	
	if (pannerNode->_distanceModel == *v) {
		return;
	}
	pannerNode->_distanceModel = *v;
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::refDistanceGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(pannerNode->_refDistance));
	
}

NAN_SETTER(PannerNode::refDistanceSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_DOUBLE_ARG;
	
	CACHE_CAS(_refDistance, v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::maxDistanceGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(pannerNode->_maxDistance));
	
}

NAN_SETTER(PannerNode::maxDistanceSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_DOUBLE_ARG;
	
	CACHE_CAS(_maxDistance, v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::rolloffFactorGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(pannerNode->_rolloffFactor));
	
}

NAN_SETTER(PannerNode::rolloffFactorSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_DOUBLE_ARG;
	
	CACHE_CAS(_rolloffFactor, v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::coneInnerAngleGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(pannerNode->_coneInnerAngle));
	
}

NAN_SETTER(PannerNode::coneInnerAngleSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_DOUBLE_ARG;
	
	CACHE_CAS(_coneInnerAngle, v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::coneOuterAngleGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(pannerNode->_coneOuterAngle));
	
}

NAN_SETTER(PannerNode::coneOuterAngleSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_DOUBLE_ARG;
	
	CACHE_CAS(_coneOuterAngle, v);
	
	// TODO: may be additional actions on change?
	
}


NAN_GETTER(PannerNode::coneOuterGainGetter) { THIS_PANNER_NODE; THIS_CHECK;
	
	RET_VALUE(JS_DOUBLE(pannerNode->_coneOuterGain));
	
}

NAN_SETTER(PannerNode::coneOuterGainSetter) { THIS_PANNER_NODE; THIS_CHECK; SETTER_DOUBLE_ARG;
	
	CACHE_CAS(_coneOuterGain, v);
	
	// TODO: may be additional actions on change?
	
}
