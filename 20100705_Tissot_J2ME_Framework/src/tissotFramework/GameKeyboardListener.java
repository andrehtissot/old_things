package tissotFramework;

/** @author André Augusto Tissot */
public class GameKeyboardListener implements Runnable {

    public boolean upKeyIsClicked = false;
    public boolean downKeyIsClicked = false;
    public boolean rightKeyIsClicked = false;
    public boolean leftKeyIsClicked = false;
    public boolean fireKeyIsClicked = false;
    public boolean gameAKeyIsClicked = false;
    public boolean gameBKeyIsClicked = false;
    public boolean gameCKeyIsClicked = false;
    public boolean gameDKeyIsClicked = false;
    public boolean upKeyIsPressed = false;
    public boolean downKeyIsPressed = false;
    public boolean rightKeyIsPressed = false;
    public boolean leftKeyIsPressed = false;
    public boolean fireKeyIsPressed = false;
    public boolean gameAKeyIsPressed = false;
    public boolean gameBKeyIsPressed = false;
    public boolean gameCKeyIsPressed = false;
    public boolean gameDKeyIsPressed = false;
    public boolean upKeyIsReleased = false;
    public boolean downKeyIsReleased = false;
    public boolean rightKeyIsReleased = false;
    public boolean leftKeyIsReleased = false;
    public boolean fireKeyIsReleased = false;
    public boolean gameAKeyIsReleased = false;
    public boolean gameBKeyIsReleased = false;
    public boolean gameCKeyIsReleased = false;
    public boolean gameDKeyIsReleased = false;
    public GameController controller;
    public boolean listen;

    public GameKeyboardListener(GameController controller) {
        this.controller = controller;
        listen = true;
    }

    public void run() {
        boolean somethingIsClicked = false;
        boolean somethingIsPressed = false;
        boolean somethingIsReleased = false;
        while (listen) {
            try {
                int keys = controller.getKeyStates();
                if ((keys & GameController.FIRE_PRESSED) != 0) {
                    if (fireKeyIsClicked) {
                        fireKeyIsClicked = fireKeyIsReleased = false;
                        fireKeyIsPressed = somethingIsPressed = true;
                        controller.fireKeyPressed();
                    } else if (!fireKeyIsPressed) {
                        fireKeyIsPressed = fireKeyIsReleased = false;
                        fireKeyIsClicked = somethingIsClicked = true;
                        controller.fireKeyClicked();
                    } else {
                        controller.fireKeyPressed();
                    }
                } else {
                    if (fireKeyIsClicked || fireKeyIsPressed) {
                        fireKeyIsClicked = fireKeyIsPressed = false;
                        fireKeyIsReleased = somethingIsReleased = true;
                        controller.fireKeyReleased();
                    } else {
                        fireKeyIsClicked = fireKeyIsPressed = fireKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.UP_PRESSED) != 0) {
                    if (upKeyIsClicked) {
                        upKeyIsClicked = upKeyIsReleased = false;
                        upKeyIsPressed = somethingIsPressed = true;
                        controller.upKeyPressed();
                    } else if (!upKeyIsPressed) {
                        upKeyIsPressed = upKeyIsReleased = false;
                        upKeyIsClicked = somethingIsClicked = true;
                        controller.upKeyClicked();
                    } else {
                        controller.upKeyPressed();
                    }
                } else {
                    if (upKeyIsClicked || upKeyIsPressed) {
                        upKeyIsClicked = upKeyIsPressed = false;
                        upKeyIsReleased = somethingIsReleased = true;
                        controller.upKeyReleased();
                    } else {
                        upKeyIsClicked = upKeyIsPressed = upKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.DOWN_PRESSED) != 0) {
                    if (downKeyIsClicked) {
                        downKeyIsClicked = downKeyIsReleased = false;
                        downKeyIsPressed = somethingIsPressed = true;
                        controller.downKeyPressed();
                    } else if (!downKeyIsPressed) {
                        downKeyIsPressed = downKeyIsReleased = false;
                        downKeyIsClicked = somethingIsClicked = true;
                        controller.downKeyClicked();
                    } else {
                        controller.downKeyPressed();
                    }
                } else {
                    if (downKeyIsClicked || downKeyIsPressed) {
                        downKeyIsClicked = downKeyIsPressed = false;
                        downKeyIsReleased = somethingIsReleased = true;
                        controller.downKeyReleased();
                    } else {
                        downKeyIsClicked = downKeyIsPressed = downKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.RIGHT_PRESSED) != 0) {
                    if (rightKeyIsClicked) {
                        rightKeyIsClicked = rightKeyIsReleased = false;
                        rightKeyIsPressed = somethingIsPressed = true;
                        controller.rightKeyPressed();
                    } else if (!rightKeyIsPressed) {
                        rightKeyIsPressed = rightKeyIsReleased = false;
                        rightKeyIsClicked = somethingIsClicked = true;
                        controller.rightKeyClicked();
                    } else {
                        controller.rightKeyPressed();
                    }
                } else {
                    if (rightKeyIsClicked || rightKeyIsPressed) {
                        rightKeyIsClicked = rightKeyIsPressed = false;
                        rightKeyIsReleased = somethingIsReleased = true;
                        controller.rightKeyReleased();
                    } else {
                        rightKeyIsClicked = rightKeyIsPressed = rightKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.LEFT_PRESSED) != 0) {
                    if (leftKeyIsClicked) {
                        leftKeyIsClicked = leftKeyIsReleased = false;
                        leftKeyIsPressed = somethingIsPressed = true;
                        controller.leftKeyPressed();
                    } else if (!leftKeyIsPressed) {
                        leftKeyIsPressed = leftKeyIsReleased = false;
                        leftKeyIsClicked = somethingIsClicked = true;
                        controller.leftKeyClicked();
                    } else {
                        controller.leftKeyPressed();
                    }
                } else {
                    if (leftKeyIsClicked || leftKeyIsPressed) {
                        leftKeyIsClicked = leftKeyIsPressed = false;
                        leftKeyIsReleased = somethingIsReleased = true;
                        controller.leftKeyReleased();
                    } else {
                        leftKeyIsClicked = leftKeyIsPressed = leftKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.GAME_A_PRESSED) != 0) {
                    if (gameAKeyIsClicked) {
                        gameAKeyIsClicked = gameAKeyIsReleased = false;
                        gameAKeyIsPressed = somethingIsPressed = true;
                        controller.gameAKeyPressed();
                    } else if (!gameAKeyIsPressed) {
                        gameAKeyIsPressed = gameAKeyIsReleased = false;
                        gameAKeyIsClicked = somethingIsClicked = true;
                        controller.gameAKeyClicked();
                    } else {
                        controller.gameAKeyPressed();
                    }
                } else {
                    if (gameAKeyIsClicked || gameAKeyIsPressed) {
                        gameAKeyIsClicked = gameAKeyIsPressed = false;
                        gameAKeyIsReleased = somethingIsReleased = true;
                        controller.gameAKeyReleased();
                    } else {
                        gameAKeyIsClicked = gameAKeyIsPressed = gameAKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.GAME_B_PRESSED) != 0) {
                    if (gameBKeyIsClicked) {
                        gameBKeyIsClicked = gameBKeyIsReleased = false;
                        gameBKeyIsPressed = somethingIsPressed = true;
                        controller.gameBKeyPressed();
                    } else if (!gameBKeyIsPressed) {
                        gameBKeyIsPressed = gameBKeyIsReleased = false;
                        gameBKeyIsClicked = somethingIsClicked = true;
                        controller.gameBKeyClicked();
                    } else {
                        controller.gameBKeyPressed();
                    }
                } else {
                    if (gameBKeyIsClicked || gameBKeyIsPressed) {
                        gameBKeyIsClicked = gameBKeyIsPressed = false;
                        gameBKeyIsReleased = somethingIsReleased = true;
                        controller.gameBKeyReleased();
                    } else {
                        gameBKeyIsClicked = gameBKeyIsPressed = gameBKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.GAME_C_PRESSED) != 0) {
                    if (gameCKeyIsClicked) {
                        gameCKeyIsClicked = gameCKeyIsReleased = false;
                        gameCKeyIsPressed = somethingIsPressed = true;
                        controller.gameCKeyPressed();
                    } else if (!gameCKeyIsPressed) {
                        gameCKeyIsPressed = gameCKeyIsReleased = false;
                        gameCKeyIsClicked = somethingIsClicked = true;
                        controller.gameCKeyClicked();
                    } else {
                        controller.gameCKeyPressed();
                    }
                } else {
                    if (gameCKeyIsClicked || gameCKeyIsPressed) {
                        gameCKeyIsClicked = gameCKeyIsPressed = false;
                        gameCKeyIsReleased = somethingIsReleased = true;
                        controller.gameCKeyReleased();
                    } else {
                        gameCKeyIsClicked = gameCKeyIsPressed = gameCKeyIsReleased = false;
                    }
                }
                if ((keys & GameController.GAME_D_PRESSED) != 0) {
                    if (gameDKeyIsClicked) {
                        gameDKeyIsClicked = gameDKeyIsReleased = false;
                        gameDKeyIsPressed = somethingIsPressed = true;
                        controller.gameDKeyPressed();
                    } else if (!gameDKeyIsPressed) {
                        gameDKeyIsPressed = gameDKeyIsReleased = false;
                        gameDKeyIsClicked = somethingIsClicked = true;
                        controller.gameDKeyClicked();
                    } else {
                        controller.gameDKeyPressed();
                    }
                } else {
                    if (gameDKeyIsClicked || gameDKeyIsPressed) {
                        gameDKeyIsClicked = gameDKeyIsPressed = false;
                        gameDKeyIsReleased = somethingIsReleased = true;
                        controller.gameDKeyReleased();
                    } else {
                        gameDKeyIsClicked = gameDKeyIsPressed = gameDKeyIsReleased = false;
                    }
                }
                if (somethingIsReleased) {
                    controller.keyboardReleased();
                }
                if (somethingIsPressed) {
                    controller.keyboardPressed();
                    Thread.sleep(200);
                }
                if (somethingIsClicked) {
                    controller.keyboardClicked();
                    Thread.sleep(160);
                }
                Thread.sleep(10);
            } catch (InterruptedException ex) {
                System.out.println("Error on GameView run method execution!: \n" + ex.getMessage());
                ex.printStackTrace();
            }
        }
    }
}
