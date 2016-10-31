package tissotFramework;

/** @author André Tissot */
public abstract class TouchGameView extends GameView {

    private TouchGameController controller;
    private static final byte CLICK = 0;
    private static final byte DRAG = 1;
    private static final byte RELEASE = 2;

    public void simulateUserClick(int pressed_x, int pressed_y) {
        controller = (TouchGameController) super.getController();
        new userSimulator(CLICK, new int[]{pressed_x, pressed_y});
    }

    public void simulateUserDrag(int dragged_x, int dragged_y) {
        controller = (TouchGameController) super.getController();
        new userSimulator(DRAG, new int[]{dragged_x, dragged_y});
    }

    public void simulateUserRelease(int released_x, int released_y) {
        controller = (TouchGameController) super.getController();
        new userSimulator(RELEASE, new int[]{released_x, released_y});
    }

    class userSimulator implements Runnable {

        public byte action;
        public int[] args;

        public userSimulator(byte whatToDo, int[] args) {
            this.args = args;
            action = whatToDo;
            (new Thread(this)).start();
        }

        public void run() {
            try {
                Thread.sleep(15);
            } catch (InterruptedException e) {
                System.out.println("Error on GameView run method execution!: \n" + e.getMessage());
            }
            switch (action) {
                case CLICK:
                    controller.pointerPressed(args[0], args[1]);
                    break;
                case DRAG:
                    controller.pointerDragged(args[0], args[1]);
                    break;
                case RELEASE:
                    controller.pointerReleased(args[0], args[1]);
            }
        }
    }
}
