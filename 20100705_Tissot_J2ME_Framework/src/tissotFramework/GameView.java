package tissotFramework;

import javax.microedition.lcdui.Graphics;

/** @author André Tissot */
abstract public class GameView implements Runnable {

    private GameController controller;
    public Graphics graph;
    public boolean runDrawer;
    public short[] backgroundColors;
    public boolean drawBackground;
    public long drawInterval = 100;
    public GameViewTemplate template;
    private boolean useBackgroundColors = false;

    public GameView() {
    }

    public GameView(GameViewTemplate template) {
        this.template = template;
        this.template.view = this;
    }

    public GameView(short[] backgroundColors) {
        if (Validations.isAColorArray(backgroundColors)) {
            this.backgroundColors = backgroundColors;
            useBackgroundColors = true;
        }
    }

    public GameView(short backgroundRedColor, short backgroundGreenColor, short backgroundBlueColor) {
        backgroundColors = new short[]{backgroundRedColor, backgroundGreenColor, backgroundBlueColor};
        useBackgroundColors = true;
    }

    public void setController(GameController controller) {
        this.controller = controller;
    }

    public GameController getController() {
        return controller;
    }

    public void run() {
        while (runDrawer) {
            if (useBackgroundColors) {
                graph.setColor(backgroundColors[0], backgroundColors[1], backgroundColors[2]);
                graph.fillRect(0, 0, GameController.WIDTH, GameController.HEIGHT);
            }
            if (template != null) {
                template.drawScreen();
            }
            drawScreen();
            controller.flushGraphics();
            try {
                Thread.sleep(drawInterval);
            } catch (InterruptedException e) {
                System.out.println("Error on GameView run method execution!: \n" + e.getMessage());
            }
        }
    }

    public void drawTranslatedString(String text, int x, int y, int anchor) {
        StringBuffer output = new StringBuffer();
        StringBuffer lastWord = new StringBuffer();
        for (int i = 0; i < text.length(); i++) {
            if(text.charAt(i) == ' '){
                output.append(Config.TEXT.get(lastWord));
                lastWord.setLength(0);
            } else {
                lastWord.append(text.charAt(i));
            }
        }
        graph.drawString(output.toString(), x, y, anchor);
    }

    abstract public void loadResources();

    abstract public void drawScreen();
}
