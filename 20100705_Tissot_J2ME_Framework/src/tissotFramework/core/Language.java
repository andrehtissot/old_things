package tissotFramework.core;

import java.io.IOException;
import java.io.InputStream;
import java.util.Hashtable;

/** @author André Tissot */
public class Language extends Hashtable {

    final String FILE;
    private int error;

    public Language(String file_path) {
        FILE = file_path;
        loadLanguage();
    }

    public synchronized Object get(Object key) {
        switch(error){
            case FILE_NOT_LOADED:
                return Config.LANGUAGE_ERROR_ON_LOAD_MESSAGE;
            case FILE_EMPTY:
                return Config.LANGUAGE_ERROR_FILE_EMPTY_MESSAGE;
            default:
                return super.get(key);
        }
    }

    private void loadLanguage() {
        if (FILE.length() != 0) {
            InputStream is = getClass().getResourceAsStream(FILE);
            byte[] buffer = new byte[5000];
            try {
                if (is.read(buffer) != 0) {
                    String file = new String(buffer);
                    if(file.indexOf('=')==-1){
                        error = FILE_EMPTY;
                    }
                    int iniLinePosition = 0;
                    int endLinePosition = 0;
                    int equalPosition = 0;
                    String key;
                    String value;
                    while (endLinePosition <= (file.length() - 1) && file.substring(endLinePosition).indexOf('\n') != -1) {
                        equalPosition = iniLinePosition + file.substring(iniLinePosition).indexOf('=');
                        iniLinePosition = file.substring(iniLinePosition, equalPosition).lastIndexOf('\n');
                        endLinePosition = file.substring(iniLinePosition).indexOf('\n');
                        key = file.substring(iniLinePosition, equalPosition).trim();
                        value = file.substring(equalPosition + 1, endLinePosition).trim();
                        put(key, value);
                    }
                } else {
                    error = FILE_EMPTY;
                }
            } catch (IOException ex) {
                error = FILE_NOT_LOADED;
                ex.printStackTrace();
            }
        }
    }

    static final byte FILE_NOT_LOADED = 0;
    static final byte FILE_EMPTY = 1;
}
