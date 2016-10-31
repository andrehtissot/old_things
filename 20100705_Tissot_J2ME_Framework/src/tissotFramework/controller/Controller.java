package tissotFramework.controller;



import tissotFramework.view.View;
import javax.microedition.lcdui.CommandListener;

/** @author André Tissot */
public interface Controller extends CommandListener {

    public View getView();

    public void setCommandListener(CommandListener l);

    public void onStartApp();

    public void onPauseApp();

    public void onDestroyApp(boolean unconditional);

    void switchActiveControllerExtraCommands();
}
