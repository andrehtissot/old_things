package tissotFramework;

/** @author André Augusto Tissot */
public class Validations {

    public static boolean isAColorArray(short[] array) {
        if (array.length == 3) {
            if (-1 < array[0] && array[0] < 256
                    && -1 < array[1] && array[1] < 256
                    && -1 < array[2] && array[2] < 256) {
                return true;
            }
        }
        return false;
    }

    public static boolean isAColorArray(int[] array) {
        if (array.length == 3) {
            if (-1 < array[0] && array[0] < 256
                    && -1 < array[1] && array[1] < 256
                    && -1 < array[2] && array[2] < 256) {
                return true;
            }
        }
        return false;
    }

    public static boolean isAColorArray(double[] array) {
        if (array.length == 3) {
            if (-1 < array[0] && array[0] < 256
                    && -1 < array[1] && array[1] < 256
                    && -1 < array[2] && array[2] < 256) {
                return true;
            }
        }
        return false;
    }

    public static boolean isAColorArray(float[] array) {
        if (array.length == 3) {
            if (-1 < array[0] && array[0] < 256
                    && -1 < array[1] && array[1] < 256
                    && -1 < array[2] && array[2] < 256) {
                return true;
            }
        }
        return false;
    }

    public static boolean isAColorArray(long[] array) {
        if (array.length == 3) {
            if (-1 < array[0] && array[0] < 256
                    && -1 < array[1] && array[1] < 256
                    && -1 < array[2] && array[2] < 256) {
                return true;
            }
        }
        return false;
    }
}
