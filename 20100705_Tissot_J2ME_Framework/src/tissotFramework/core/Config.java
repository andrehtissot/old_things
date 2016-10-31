package tissotFramework.core;

import java.io.IOException;
import tissotFramework.controller.Controller;
import java.io.InputStream;
import tissotFramework.controller.ErrorScreen;

/** @author André Tissot */
public final class Config {

    public static Language TEXT;
    static Controller FIRST_CONTROLLER;
    public static String PROJECT_NAME;
    public static final java.util.Hashtable GLOBALS = new java.util.Hashtable();

    static void load() throws Exception {
        InputStream in = null;
        try {
            in = GLOBALS.getClass().getResourceAsStream("/framework.conf");
            if (in == null) {
                new ErrorScreen("Config file not found!");
            }
            byte[] buffer = new byte[1000];
            if (in.read(buffer) != 0) {
                String text = new String(buffer);
                String line;
                String language = null;
                do {
                    line = text.substring(0, text.toString().indexOf("\n") + 1);
                    text = text.substring(text.toString().indexOf("\n") + 1);
                    if (line.startsWith("Default System Language=") || line.startsWith("Default System Language =")) {
                        language = line.substring(line.indexOf("=") + 1).trim();
                    } else if (line.startsWith("First Controller Called=") || line.startsWith("First Controller Called =")) {
                        try {
                            System.out.println(line.substring(line.indexOf("=") + 1).trim());
                            FIRST_CONTROLLER = (Controller) Class.forName(line.substring(line.indexOf("=") + 1).trim()).newInstance();
                        } catch (Exception ex) {
                            in.close();
                            throw new Exception("framework.conf: First Controller Called is not valid: " + ex.getMessage());
                        }
                    } else if (line.startsWith("Project Name=") || line.startsWith("Project Name =")) {
                        PROJECT_NAME = line.substring(line.indexOf("=") + 1).trim();
                    } else if (line.indexOf("=") >= 0) {
                        GLOBALS.put(line.substring(0, line.indexOf("=")).trim(), line.substring(line.indexOf("=") + 1).trim());
                    }
                } while (line.length() > 1 || line.equals("\n"));
                if (language == null) {
                    in.close();
                    throw new Exception("framework.conf: Default System Language is not defined");
                }
                if (FIRST_CONTROLLER == null) {
                    in.close();
                    throw new Exception("framework.conf: First Controller Called is not defined");
                }
                if (PROJECT_NAME == null) {
                    in.close();
                    throw new Exception("framework.conf: Project Name is not defined");
                }
            }
        } catch (Exception e) {
            new ErrorScreen(e.getMessage());
        } finally {
            try {
                in.close();
            } catch (IOException ex) {
                new ErrorScreen(ex.getMessage());
            }
        }
    }
    static String LANGUAGE_ERROR_ON_LOAD_MESSAGE = "Error on Language file load!";
    static String LANGUAGE_ERROR_FILE_EMPTY_MESSAGE = "Language file is empty!";
}
