#include "stdafx.h"
#include "Animation.h"

Animation::Animation(const std::string& name_, const SpriteSource* spriteSource_, unsigned frameCount_, unsigned frameStart_, float frameDuration_)
	: accumulator(0.0f), currentVirtualFrame(0), frameDuration(frameDuration_), frameCount(frameCount_), frameStart(frameStart_), name(name_), spriteSource(spriteSource_)
{
}

unsigned Animation::GetCurrentFrameIndex(float dt, float playbackSpeed, bool looping, bool* isDone) const
{
	currentVirtualFrame = GetVirtualIndex(dt, playbackSpeed);

	if (looping)
	{
		if (currentVirtualFrame == frameCount)
		{
			currentVirtualFrame = 0;
		}
	}
	else
	{
		if (currentVirtualFrame + 1 > frameCount)
		{
			currentVirtualFrame = frameCount;
		}
	}

	if (isDone != nullptr)
	{
		if (currentVirtualFrame == frameCount - 1)
		{
			*isDone = true;
		}
		else
		{
			*isDone = false;
		}
	}

	return currentVirtualFrame + frameStart;
}

const std::string& Animation::GetName() const
{
	return name;
}

const SpriteSource* Animation::GetSpriteSource() const
{
	return spriteSource;
}

unsigned Animation::Play() const
{
	accumulator = 0;
	currentVirtualFrame = 0;
	return frameStart;
}

unsigned Animation::GetVirtualIndex(float dt_, float playbackSpeed_) const
{
	accumulator += dt_ * playbackSpeed_;

	if (frameDuration == 0)
	{
		currentVirtualFrame++;
		return currentVirtualFrame;
	}

	while (accumulator >= frameDuration)
	{
		currentVirtualFrame++;
		accumulator -= frameDuration;
	}

	return currentVirtualFrame;
}
