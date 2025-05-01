#pragma once
#include "../../pch.h"
#include "../Pointers.hpp"

// I'm lazy and I'm just reusing old code fast bec why not



class CC
{
public:

	inline static bool NoClipToggle{false};

	inline static bool isNoClip(std::string& CMD)
	{
		if (CMD != "ghost") return false;

		NoClipToggle = !NoClipToggle;

		Player0()->Pawn->bActorEnableCollision = NoClipToggle;

		reinterpret_cast<SDK::AWillie_BP_C*>(Player0()->Pawn)->bActorEnableCollision = NoClipToggle;

		reinterpret_cast<SDK::AWillie_BP_C*>(Player0()->Pawn)->Disentergrate();

		NoClipToggle ? Log("Enabled ghost") : Log("Disabled ghost");

		return true;
	}



};