//------------------------------------------------------------------------------
//
// File Name: Animator.cpp
// Author(s): Shain Allen
// Project: CS230Lab5
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Animator.h"
#include "Animation.h"
#include "Sprite.h"
#include "SpriteSource.h"
#include "Component.h"
#include "GameObject.h"

Animator::Animator()
	: Component("Animator"), animationIndex(0), isDone(false), isLooping(false), isRunning(false), playbackSpeed(0.0f), sprite(nullptr)
{
}

Component* Animator::Clone() const
{
	return new Animator(*this);
}

void Animator::Initialize()
{
	sprite = M_GetOwnerComponent(Sprite);
}

void Animator::Update(float dt)
{
	if (!isRunning)
		return;

	sprite->SetFrame(animationList[animationIndex]->GetCurrentFrameIndex(dt, playbackSpeed, isLooping, &isDone));
}

void Animator::Play(size_t animationIndex_, float playbackSpeed_, bool loop_)
{
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
