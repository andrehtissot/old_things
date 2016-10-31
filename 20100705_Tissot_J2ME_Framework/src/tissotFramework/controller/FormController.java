package tissotFramework.controller;

import tissotFramework.view.View;
import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.Form;
import javax.microedition.lcdui.Item;
import javax.microedition.lcdui.ItemStateListener;
import tissotFramework.view.FormDateTextField;
import tissotFramework.view.FormView;

/** @author André Augusto Tissot */
public class FormController extends Form implements Controller, ItemStateListener {

    public FormView screenView;

    public FormController(String title) {
        super(title);
    }

    public View getView() {
        return screenView;
    }

    public void onStartApp() {
    }

    public void onPauseApp() {
    }

    public void onDestroyApp(boolean unconditional) {
    }

    public void switchActiveControllerExtraCommands() {
    }

    public void commandAction(Command c, Displayable d) {
    }

    public void itemStateChanged(Item item) {
        if (item instanceof FormDateTextField) {
            ((FormDateTextField) item).applyMask();
        }
    }
}
