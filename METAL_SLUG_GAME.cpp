#include "raylib.h"
#include <iostream>

using namespace std;

// Player structure
enum Direction { UP, DOWN, RIGHT, LEFT };

struct player {
    int x, y;
    Direction direction;
    int up_key, down_key, right_key, left_key, shoot_key;
    int health;
    int score;
    bool shooting;
    bool jumping;
    int weapon;
};
#include "raylib.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
//
//#define TOTAL_FRAMES 5  // Total number of walking frames
//#define PLAYER_FRAMES 56  // Total number of player walking frames
//
//int screenWidth = 1920;
//int screenHeight = 1070;
//// Function to check if the mouse is within a clickable area
//bool IsMouseOverButton(Rectangle buttonArea) {
//    return CheckCollisionPointRec(GetMousePosition(), buttonArea);
//}
//
//int mainmm() {
//    InitWindow(screenWidth, screenHeight, "Metal Slug - Starting Screen Animation");
//    SetTargetFPS(60);
//
//    // Load starting screen frames
//    Texture2D startFrames[TOTAL_FRAMES];
//    for (int i = 0; i < TOTAL_FRAMES; i++) {
//        stringstream ss;
//        ss << "assets/starting/start" << (i + 1) << ".png";
//        string fileName = ss.str();
//        startFrames[i] = LoadTexture(fileName.c_str());
//    }
//
//    // Load the menu background, controls screen, and level selection screen
//    Texture2D menuBackground = LoadTexture("assets/menu_background.png");
//    Texture2D controlsScreen = LoadTexture("assets/controls.png");
//    Texture2D levelSelectionScreen = LoadTexture("assets/level_selection.png");
//
//    // Load player walking animation frames
//    Texture2D walkFrames[PLAYER_FRAMES];
//    for (int i = 0; i < PLAYER_FRAMES; i++) {
//        stringstream ss;
//        ss << "assets/playerwalk_right/player-" << i << ".png";
//        walkFrames[i] = LoadTexture(ss.str().c_str());
//    }
//
//    Rectangle startButtonArea = { 520, 420, 830, 80 };
//    Rectangle quitButtonArea = { 520, 560, 830, 80 };
//
//    int currentFrame = 0;
//    int frameCounter = 0;
//    int frameSpeed = 65;
//
//    bool showMenu = false;
//    bool showControls = false;
//    bool showLevelSelection = false;
//
//    int playerFrame = 0;
//    int playerFrameCounter = 0;
//    int playerFrameSpeed = 2;  // Faster player animation speed
//    float playerX = 100;
//    float playerY = 800;
//    bool isWalking = false;
//
//    while (!WindowShouldClose()) {
//        frameCounter++;
//
//        if (frameCounter >= frameSpeed && !showMenu) {
//            frameCounter = 0;
//            currentFrame++;
//            if (currentFrame >= TOTAL_FRAMES) {
//                showMenu = true;
//            }
//        }
//
//        BeginDrawing();
//        ClearBackground(LIGHTGRAY);
//
//        if (!showMenu) {
//            DrawTexturePro(startFrames[currentFrame % TOTAL_FRAMES], { 0, 0, (float)startFrames[currentFrame % TOTAL_FRAMES].width, (float)startFrames[currentFrame % TOTAL_FRAMES].height }, { 0, 0, (float)screenWidth, (float)screenHeight }, { 0, 0 }, 0.0f, WHITE);
//        }
//        else if (!showControls) {
//            DrawTexturePro(menuBackground, { 0, 0, (float)menuBackground.width, (float)menuBackground.height }, { 0, 0, (float)screenWidth, (float)screenHeight }, { 0, 0 }, 0.0f, WHITE);
//
//            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                if (IsMouseOverButton(startButtonArea)) {
//                    showControls = true;
//                }
//                if (IsMouseOverButton(quitButtonArea)) {
//                    CloseWindow();
//                    return 0;
//                }
//            }
//        }
//        else if (!showLevelSelection) {
//            DrawTexturePro(controlsScreen, { 0, 0, (float)controlsScreen.width, (float)controlsScreen.height }, { 0, 0, (float)screenWidth, (float)screenHeight }, { 0, 0 }, 0.0f, WHITE);
//
//            if (IsKeyPressed(KEY_ESCAPE)) {
//                showControls = false;
//            }
//            if (IsKeyPressed(KEY_ENTER)) {
//                showLevelSelection = true;
//            }
//        }
//        else {
//            DrawTexturePro(levelSelectionScreen, { 0, 0, (float)levelSelectionScreen.width, (float)levelSelectionScreen.height }, { 0, 0,(float)screenWidth,(float)screenHeight }, { 0, 0 }, 0.0f, WHITE);
//
//            if (IsKeyPressed(KEY_ESCAPE)) {
//                showLevelSelection = false;
//            }
//        }
//
//        // Player Movement Logic (Active Throughout the Game)
//        if (IsKeyDown(KEY_D)) {
//            isWalking = true;
//            playerX += 4;
//
//            playerFrameCounter++;
//            if (playerFrameCounter >= playerFrameSpeed) {
//                playerFrameCounter = 0;
//                playerFrame = (playerFrame + 1) % PLAYER_FRAMES;
//            }
//        }
//        else {
//            isWalking = false;
//        }
//
//        if (isWalking) {
//            DrawTexture(walkFrames[playerFrame], playerX, playerY, WHITE);
//        }
//        else {
//            DrawTexture(walkFrames[0], playerX, playerY, WHITE);
//        }
//
//        EndDrawing();
//    }
//
//    for (int i = 0; i < TOTAL_FRAMES; i++) {
//        UnloadTexture(startFrames[i]);
//    }
//    UnloadTexture(menuBackground);
//    UnloadTexture(controlsScreen);
//    UnloadTexture(levelSelectionScreen);
//
//    for (int i = 0; i < PLAYER_FRAMES; i++) {
//        UnloadTexture(walkFrames[i]);
//    }
//
//    CloseWindow();
//    return 0;
//}

#define TOTAL_FRAMES 5  // Total number of starting screen frames
#define PLAYER_FRAMES 56  // Total number of player walking frames

int screenWidth = 1920;
int screenHeight = 1070;

// Function to check if the mouse is within a clickable area
bool IsMouseOverButton(Rectangle buttonArea) {
    return CheckCollisionPointRec(GetMousePosition(), buttonArea);
}

int main() {
    InitWindow(screenWidth, screenHeight, "Metal Slug - Starting Screen Animation");
    SetTargetFPS(60);

    // Load starting screen frames
    Texture2D startFrames[TOTAL_FRAMES];
    for (int i = 0; i < TOTAL_FRAMES; i++) {
        stringstream ss;
        ss << "assets/starting/start" << (i + 1) << ".png";
        string fileName = ss.str();
        startFrames[i] = LoadTexture(fileName.c_str());
    }

    // Load the menu background, controls screen, and level selection screen
    Texture2D menuBackground = LoadTexture("assets/menu_background.png");
    Texture2D controlsScreen = LoadTexture("assets/controls.png");
    Texture2D levelSelectionScreen = LoadTexture("assets/level_selection.png");

    // Load player walking animation frames (for right and left movement)
    Texture2D walkFrames[PLAYER_FRAMES];
    Texture2D walkFramesBackward[PLAYER_FRAMES];

    for (int i = 0; i < PLAYER_FRAMES; i++) {
        stringstream ssRight, ssLeft;
        ssRight << "assets/playerwalk_right/player-" << i << ".png";
        ssLeft << "assets/playerwalk_-left/player-" << i << ".png";

        walkFrames[i] = LoadTexture(ssRight.str().c_str());
        walkFramesBackward[i] = LoadTexture(ssLeft.str().c_str());
    }

    Rectangle startButtonArea = { 520, 420, 830, 80 };
    Rectangle quitButtonArea = { 520, 560, 830, 80 };

    int currentFrame = 0;
    int frameCounter = 0;
    int frameSpeed = 65;

    bool showMenu = false;
    bool showControls = false;
    bool showLevelSelection = false;

    int playerFrame = 0;
    int playerFrameCounter = 0;
    int playerFrameSpeed = 2;  // Faster player animation speed
    float playerX = 100;
    float playerY = 800;
    bool isWalking = false;
    bool isWalkingBackward = false;

    while (!WindowShouldClose()) {
        frameCounter++;

        if (frameCounter >= frameSpeed && !showMenu) {
            frameCounter = 0;
            currentFrame++;
            if (currentFrame >= TOTAL_FRAMES) {
                showMenu = true;
            }
        }

        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        if (!showMenu) {
            DrawTexturePro(startFrames[currentFrame % TOTAL_FRAMES], { 0, 0, (float)startFrames[currentFrame % TOTAL_FRAMES].width, (float)startFrames[currentFrame % TOTAL_FRAMES].height }, { 0, 0, (float)screenWidth, (float)screenHeight }, { 0, 0 }, 0.0f, WHITE);
        }
        else if (!showControls) {
            DrawTexturePro(menuBackground, { 0, 0, (float)menuBackground.width, (float)menuBackground.height }, { 0, 0, (float)screenWidth, (float)screenHeight }, { 0, 0 }, 0.0f, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (IsMouseOverButton(startButtonArea)) {
                    showControls = true;
                }
                if (IsMouseOverButton(quitButtonArea)) {
                    CloseWindow();
                    return 0;
                }
            }
        }
        else if (!showLevelSelection) {
            DrawTexturePro(controlsScreen, { 0, 0, (float)controlsScreen.width, (float)controlsScreen.height }, { 0, 0, (float)screenWidth, (float)screenHeight }, { 0, 0 }, 0.0f, WHITE);

            if (IsKeyPressed(KEY_ESCAPE)) {
                showControls = false;
            }
            if (IsKeyPressed(KEY_ENTER)) {
                showLevelSelection = true;
            }
        }
        else {
            DrawTexturePro(levelSelectionScreen, { 0, 0, (float)levelSelectionScreen.width, (float)levelSelectionScreen.height }, { 0, 0,(float)screenWidth,(float)screenHeight }, { 0, 0 }, 0.0f, WHITE);

            if (IsKeyPressed(KEY_ESCAPE)) {
                showLevelSelection = false;
            }
        }

        // Player Movement Logic (Active Throughout the Game)
        if (IsKeyDown(KEY_D)) {
            isWalking = true;
            isWalkingBackward = false;
            playerX += 4;

            playerFrameCounter++;
            if (playerFrameCounter >= playerFrameSpeed) {
                playerFrameCounter = 0;
                playerFrame = (playerFrame + 1) % PLAYER_FRAMES;
            }
        }
        else if (IsKeyDown(KEY_A)) {
            isWalkingBackward = true;
            isWalking = false;
            playerX -= 4;

            playerFrameCounter++;
            if (playerFrameCounter >= playerFrameSpeed) {
                playerFrameCounter = 0;
                playerFrame = (playerFrame + 1) % PLAYER_FRAMES;
            }
        }
        else {
            isWalking = false;
            isWalkingBackward = false;
        }

        if (isWalking) {
            DrawTexture(walkFrames[playerFrame], playerX, playerY, WHITE);
        }
        else if (isWalkingBackward) {
            DrawTexture(walkFramesBackward[playerFrame], playerX, playerY, WHITE);
        }
        else {
            DrawTexture(walkFrames[0], playerX, playerY, WHITE);
        }

        EndDrawing();
    }

    for (int i = 0; i < TOTAL_FRAMES; i++) {
        UnloadTexture(startFrames[i]);
    }
    UnloadTexture(menuBackground);
    UnloadTexture(controlsScreen);
    UnloadTexture(levelSelectionScreen);

    for (int i = 0; i < PLAYER_FRAMES; i++) {
        UnloadTexture(walkFrames[i]);
        UnloadTexture(walkFramesBackward[i]);
    }

    CloseWindow();
    return 0;
}
