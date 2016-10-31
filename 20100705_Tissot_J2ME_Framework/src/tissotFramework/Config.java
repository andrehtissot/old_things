package tissotFramework;

import java.io.InputStream;

/** @author André Tissot */
public final class Config {

    public static Language TEXT;
    static Controller FIRST_CONTROLLER;
    public static String PROJECT_NAME;
    public static final java.util.Vector GLOBALS = new java.util.Vector();

    static {
        try {
            InputStream in = GLOBALS.getClass().getResourceAsStream("/framework.conf");
            byte[] buffer = new byte[1000];
            if (in.read(buffer) != 0) {
                String text = new String(buffer);
                int i = text.indexOf("Default System Language File=");
                if (i == -1) {
                    i = text.indexOf("Default System Language File =");
                }
                try {
                    TEXT = new Language(text.substring(i + text.substring(i).indexOf('=') + 1, i + text.substring(i).indexOf('\n')).trim());

                } catch (Exception ex) {
                    ex.printStackTrace();
//                    LANGUAGE = new Language();
                }
                if ((i = text.indexOf("First Controller Called=")) == -1) {
                    i = text.indexOf("First Controller Called =");
                }
                try {
                    FIRST_CONTROLLER = (Controller) Class.forName(text.substring(i + text.substring(i).indexOf('=') + 1, i + text.substring(i).indexOf('\n')).trim()).newInstance();
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
                if ((i = text.indexOf("Project Name=")) == -1) {
                    i = text.indexOf("Project Name =");
                }
                PROJECT_NAME = text.substring(i + text.substring(i).indexOf('=') + 1, i + text.substring(i).indexOf('\n')).trim();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static String LANGUAGE_ERROR_ON_LOAD_MESSAGE = "Error on Language file load!";
    static String LANGUAGE_ERROR_FILE_EMPTY_MESSAGE = "Language file is empty!";
}
