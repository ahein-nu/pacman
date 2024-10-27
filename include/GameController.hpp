#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include <SDL2/SDL.h>

#include "BlinkyController.hpp"
#include "ClydeController.hpp"
#include "GameData.hpp"
#include "GameInterface.hpp"
#include "GameSoundController.hpp"
#include "InkyController.hpp"
#include "Map.hpp"
#include "PinkyController.hpp"
#include "PlayerController.hpp"

class GameController {
public:
  GameController(GameData &, Map &);
  ~GameController();
  void update();
  void updateScore(const int &toAdd);
  void handleKeyEvent(SDL_KeyboardEvent &);
  void restart();

private:
  GameSoundController _soundController;
  Map &_map;
  GameData &_data;
  PlayerController _playerController;
  std::array<GhostController *, 4> _ghosts;

  static const int ENERGIZED_TICKS = 1200000;
  Timer _energizedTimer;
#ifndef NDEBUG
  static const int READINESS_TICKS = 1000;
#else
  static const int READINESS_TICKS = 4000;
#endif
  Timer _readinessTimer;
  Timer _ghostWhereEatenTimer;
  static const short GHOST_WHERE_EATEN_TICKS = 1300;
};

#endif