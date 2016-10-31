package tissotFramework;



import javax.microedition.lcdui.CommandListener;

/** @author André Tissot */
public interface Controller extends CommandListener {

    public GameView getView();

    public void setCommandListener(CommandListener l);

    public void onStartApp();

    public void onPauseApp();

    public void onDestroyApp(boolean unconditional);

    void switchActiveControllerExtraCommands();
}
