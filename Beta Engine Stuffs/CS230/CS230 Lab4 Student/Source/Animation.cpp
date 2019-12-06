#include "stdafx.h"
#include "Animation.h"

Animation::Animation(const std::string& name, const SpriteSource* spriteSource, unsigned frameCount, unsigned frameStart, float frameDuration)
	: accumulator(), currentVirtualFrame()
{

}

unsigned Animation::GetCurrentFrameIndex(float dt, float playbackSpeed, bool looping, bool* isDone) const
{
	return 0;
}

const std::string& Animation::GetName() const
{
	// TODO: insert return statement here
}

const SpriteSource* Animation::GetSpriteSource() const
{
	return nullptr;
}

unsigned Animation::Play() const
{
	return 0;
}

unsigned Animation::GetVirtualIndex(float dt, float playbackSpeed) const
{
	return 0;
}
