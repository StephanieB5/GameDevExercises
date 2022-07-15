// LinearAlgebra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3F.h"
#include "Matrix.h"
#include "OrionMath.h"  

enum class Exercise 
{
    PlayerInRoomA,
    WhichSideIsTheLoot,
    TransformingSpaces
};

bool IsPlayerInRoomA(Vector3F const playerPos)
{
    Vector3F const centreRoomA(2.f, 18.f, 1.f);
    Vector3F const centreRoomB(10.f, 10.f, 1.f);
    Vector3F const centreHall(6.f, 14.f, 1.f);

//-----------------------------------------------------------------------------
// For the delegates to fill in

    // Replace this line
    return false;
//-------------------------------------------------------------------------------
}

bool IsTheLootToTheRight(Vector3F const lootPos)
{
    Vector3F const up(0.f, 0.f, 1.f);
    Vector3F const front(-0.707f, 0.707f, 0.f);
    Vector3F const npcPos(10.f, 10.f, 5.f);

//-----------------------------------------------------------------------------
// For the delegates to fill in

    // Replace this line
    return false;
//-------------------------------------------------------------------------------
}

bool TransformToWorldSpace(Vector3F const direction, Vector3F const position, Vector3F const origin)
{
    Matrix traslationToWS =
    {
        1.f, 0.f, 0.f, 10.f,
        0.f, 1.f, 0.f, 10.f,
        0.f, 0.f, 1.f, 5.0f,
        0.f, 0.f, 0.f, 1.f
    };

    Matrix rotationToWS =
    {
        0.5f, 0.f, 0.86602f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        -0.86602f, 0.f, 0.5f, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
    Matrix scaleToWS =
    {
        2.f, 0.f, 0.f, 0.f,
        0.f, 2.f, 0.f, 0.f,
        0.f, 0.f, 2.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    };

    Matrix temp;
    temp.clearToZero();

    // You will need to calculate the value for this
    Matrix toWorldSpace;
    toWorldSpace.clearToZero();

    // You will need to calculate the value of these
    Vector4F worldSpaceDir4F;
    Vector4F worldSpacePos4F;
    Vector4F worldSpaceOrigin4F;

//-----------------------------------------------------------------------------
// For the delegates to fill in

//-------------------------------------------------------------------------------

    Vector3F worldSpaceDir = { 1.f, 0.f, -1.73204f};
    Vector3F worldSpacePos = { 12.73204f, 12.f, 4.26796f};
    Vector3F worldSpaceOrigin = {10.f, 10.f, 5.f};

    return (worldSpaceDir.IsEqual(worldSpaceDir4F.MakeVector3F())
                && worldSpacePos.IsEqual(worldSpacePos4F.MakeVector3F())
                && worldSpaceOrigin.IsEqual(worldSpaceOrigin4F.MakeVector3F()));
}

int main()
{
    Exercise selectedExercise = Exercise::TransformingSpaces;
    switch (selectedExercise)
    {
    case Exercise::PlayerInRoomA:
        {
            std::cout << "True or False: The player is in Room A with the sweet loot." << std::endl;
            Vector3F const playerPos(6.f, 10.f, 1.f);
            bool playerWithNPC = IsPlayerInRoomA(playerPos);
            std::cout << std::boolalpha << playerWithNPC << std::endl;
        }
        break;

    case Exercise::WhichSideIsTheLoot:
        {
            std::cout << "True or False: The loot is to the right of the NPC." << std::endl;
            Vector3F const lootPos(10.f, 14.f, 5.f);
            bool lootIsToTheRight = IsTheLootToTheRight(lootPos);
            std::cout << std::boolalpha << lootIsToTheRight << std::endl;
            break;
        }

    case Exercise::TransformingSpaces:
        {
            std::cout << "True or False: The direction and position been transformed correctly." << std::endl;
            Vector3F const direction(1.f, 0.f, 0.f);
            Vector3F const position(1.f, 1.f, 1.f);
            Vector3F const origin(0.f, 0.f, 0.f);
            bool dataTransformed = TransformToWorldSpace(direction, position, origin);
            std::cout << std::boolalpha << dataTransformed << std::endl;
            break;
        }
    }

    std::cout << "Press Enter to continue" << std::endl;
    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
