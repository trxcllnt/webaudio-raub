#include <cstdlib>


#include "media-stream-audio-source-node.hpp"


using namespace v8;
using namespace node;
using namespace std;


// ------ Aux macros

#define THIS_MEDIA_STREAM_AUDIO_SOURCE_NODE                                                    \
	MediaStreamAudioSourceNode *mediaStreamAudioSourceNode = Nan::ObjectWrap::Unwrap<MediaStreamAudioSourceNode>(info.This());

#define THIS_CHECK                                                            \
	if (mediaStreamAudioSourceNode->_isDestroyed) return;

#define CACHE_CAS(CACHE, V)                                                   \
	if (mediaStreamAudioSourceNode->CACHE == V) {                                           \
		return;                                                               \
	}                                                                         \
	mediaStreamAudioSourceNode->CACHE = V;


// ------ Constructor and Destructor

MediaStreamAudioSourceNode::MediaStreamAudioSourceNode() :
AudioNode() {
	
	_isDestroyed = false;
	
}


MediaStreamAudioSourceNode::~MediaStreamAudioSourceNode() {
	
	_destroy();
	
}


void MediaStreamAudioSourceNode::_destroy() { DES_CHECK;
	
	_isDestroyed = true;
	
	AudioNode::_destroy();
	
}


// ------ Methods and props



NAN_GETTER(MediaStreamAudioSourceNode::mediaStreamGetter) { THIS_MEDIA_STREAM_AUDIO_SOURCE_NODE; THIS_CHECK;
	
	RET_VALUE(JS_OBJ(mediaStreamAudioSourceNode->_mediaStream));
	
}


// ------ System methods and props for ObjectWrap

V8_STORE_FT MediaStreamAudioSourceNode::_protoMediaStreamAudioSourceNode;
V8_STORE_FUNC MediaStreamAudioSourceNode::_ctorMediaStreamAudioSourceNode;


void MediaStreamAudioSourceNode::init(V8_VAR_OBJ target) {
	
	V8_VAR_FT proto = Nan::New<FunctionTemplate>(newCtor);

	// class MediaStreamAudioSourceNode inherits AudioNode
	V8_VAR_FT parent = Nan::New(AudioNode::_protoAudioNode);
	proto->Inherit(parent);
	
	proto->InstanceTemplate()->SetInternalFieldCount(1);
	proto->SetClassName(JS_STR("MediaStreamAudioSourceNode"));
	
	
	// Accessors
	V8_VAR_OT obj = proto->PrototypeTemplate();
	ACCESSOR_R(obj, isDestroyed);
	
	ACCESSOR_R(obj, mediaStream);
	
	// -------- dynamic
	
	Nan::SetPrototypeMethod(proto, "destroy", destroy);
	
	
	
	// -------- static
	
	V8_VAR_FUNC ctor = Nan::GetFunction(proto).ToLocalChecked();
	
	_protoMediaStreamAudioSourceNode.Reset(proto);
	_ctorMediaStreamAudioSourceNode.Reset(ctor);
	
	Nan::Set(target, JS_STR("MediaStreamAudioSourceNode"), ctor);
	
	
}


bool MediaStreamAudioSourceNode::isMediaStreamAudioSourceNode(V8_VAR_OBJ obj) {
	return Nan::New(_protoMediaStreamAudioSourceNode)->HasInstance(obj);
}


V8_VAR_OBJ MediaStreamAudioSourceNode::getNew() {
	
	V8_VAR_FUNC ctor = Nan::New(_ctorMediaStreamAudioSourceNode);
	// V8_VAR_VAL argv[] = { /* arg1, arg2, ... */ };
	return Nan::NewInstance(ctor, 0/*argc*/, nullptr/*argv*/).ToLocalChecked();
	
}


NAN_METHOD(MediaStreamAudioSourceNode::newCtor) {
	
	CTOR_CHECK("MediaStreamAudioSourceNode");
	
	MediaStreamAudioSourceNode *mediaStreamAudioSourceNode = new MediaStreamAudioSourceNode();
	mediaStreamAudioSourceNode->Wrap(info.This());
	
	RET_VALUE(info.This());
	
}


NAN_METHOD(MediaStreamAudioSourceNode::destroy) { THIS_MEDIA_STREAM_AUDIO_SOURCE_NODE; THIS_CHECK;
	
	mediaStreamAudioSourceNode->emit("destroy");
	
	mediaStreamAudioSourceNode->_destroy();
	
}


NAN_GETTER(MediaStreamAudioSourceNode::isDestroyedGetter) { THIS_MEDIA_STREAM_AUDIO_SOURCE_NODE;
	
	RET_VALUE(JS_BOOL(mediaStreamAudioSourceNode->_isDestroyed));
	
}
