#include "stdafx.h"
#include "Animator.h"
#include "Animation.h"
#include "Sprite.h"
#include "SpriteSource.h"

Animator::Animator(Sprite* sprite_)
	: animationIndex(0), isDone(false), isLooping(false), isRunning(false), playbackSpeed(0.0f), sprite(sprite_)
{
}

void Animator::Update(float dt)
{
	std::cout << "Animator::Update" << std::endl;

	if (!isRunning)
		return;

	sprite->SetFrame(animationList[animationIndex]->GetCurrentFrameIndex(dt, playbackSpeed, isLooping, &isDone));
}

void Animator::Play(size_t animationIndex_, float playbackSpeed_, bool loop_)
{
	std::cout << "Animator::Play" << std::endl;

	if (animationIndex_ > animationList.Size() - 1)
		return;

	playbackSpeed = playbackSpeed_;
	isLooping = loop_;
	isRunning = true;
	

	const Animation* currentAnimation = animationList[animationIndex_];

	if (currentAnimation != nullptr)
	{
		if (currentAnimation->GetSpriteSource() != nullptr)
			sprite->SetSpriteSource(currentAnimation->GetSpriteSource());

		sprite->SetFrame(currentAnimation->Play());
	}
	isDone = false;
}

size_t Animator::AddAnimation(const Animation* animation)
{
	animationList.PushBack(animation);
	return animationList.Size() - 1;
}

size_t Animator::GetCurrentAnimationIndex() const
{
	return animationIndex;
}

size_t Animator::GetAnimationIndex(const std::string& name_) const
{
	for (int i = 0; i < animationList.Size(); i++)
		if (animationList[i]->GetName() == name_)
			return i;
	
	return 0;
}

bool Animator::IsDone() const
{
	return isDone;
}

void Animator::SetPlaybackSpeed(float speed)
{
	playbackSpeed = speed;
}
