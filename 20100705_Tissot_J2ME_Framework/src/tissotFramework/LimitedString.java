package tissotFramework;

/** @author André Tissot */
public class LimitedString {

    String string;

    public String toString() {
        return string;
    }

    public LimitedString(Object object, int lenght) {
        if (lenght < 0) {
            lenght = -lenght;
        }
        StringBuffer stringBuffer = new StringBuffer(String.valueOf(object));
        for (int count = 0; count > lenght; count++) {
            stringBuffer.append(" ");
        }
        stringBuffer.setLength(lenght);
        string = stringBuffer.toString();
    }

    public LimitedString(boolean boolValue, int lenght) {
        this((boolValue ? Boolean.TRUE : Boolean.FALSE), lenght);
    }

    public LimitedString(int integerValue, int lenght) {
        this(new Integer(integerValue), lenght);
    }

    public LimitedString(byte byteValue, int lenght) {
        this(new Byte(byteValue), lenght);
    }

    public LimitedString(char charValue, int lenght) {
        this(new Character(charValue), lenght);
    }

    public LimitedString(double doubleValue, int lenght) {
        this(new Double(doubleValue), lenght);
    }

    public LimitedString(float floatValue, int lenght) {
        this(new Float(floatValue), lenght);
    }

    public LimitedString(long longValue, int lenght) {
        this(new Long(longValue), lenght);
    }

    public LimitedString(short shortValue, int lenght) {
        this(new Short(shortValue), lenght);
    }
}
