package tissotFramework.util;

import java.util.Vector;

/** @author André Tissot */
public class FloatValuesVector extends Vector {

    private int NaNRegisters;

    public void add(DoubleValuesVector vector){
        for(int i=0;i<vector.size();i++){
            super.addElement(vector.elementAt(i));
        }
    }

    public void add(FloatValuesVector vector){
        for(int i=0;i<vector.size();i++){
            super.addElement(vector.elementAt(i));
        }
    }

    public void add(IntegerValuesVector vector){
        for(int i=0;i<vector.size();i++){
            super.addElement(vector.elementAt(i));
        }
    }

    public void add(LongValuesVector vector){
        for(int i=0;i<vector.size();i++){
            super.addElement(vector.elementAt(i));
        }
    }
    
    public void add(float value) {
        super.addElement(new Float(value));
    }

    public void add(double value) {
        super.addElement(new Float(value));
    }

    public void add(short value) {
        super.addElement(new Float(value));
    }

    public void add(int value) {
        super.addElement(new Float(value));
    }

    public void add(long value) {
        super.addElement(new Float(value));
    }

    public void add(byte value) {
        super.addElement(new Float(value));
    }

    public void add(char value) {
        super.addElement(new Float(value));
    }

    public void add(Object value) {
        super.addElement(value);
    }

    public void insertAt(float value, int index) {
        super.insertElementAt(new Float(value), index);
    }

    public void insertAt(double value, int index) {
        super.insertElementAt(new Float(value), index);
    }

    public void insertAt(short value, int index) {
        super.insertElementAt(new Float(value), index);
    }

    public void insertAt(int value, int index) {
        super.insertElementAt(new Float(value), index);
    }

    public void insertAt(long value, int index) {
        super.insertElementAt(new Float(value), index);
    }

    public void insertAt(byte value, int index) {
        super.insertElementAt(new Float(value), index);
    }

    public void insertAt(char value, int index) {
        super.insertElementAt(new Float(value), index);
    }

    public void insertAt(Object value, int index) {
        super.insertElementAt(value, index);
    }

    public void setAt(float value, int index) {
        super.setElementAt(new Float(value), index);
    }

    public void setAt(double value, int index) {
        super.setElementAt(new Float(value), index);
    }

    public void setAt(short value, int index) {
        super.setElementAt(new Float(value), index);
    }

    public void setAt(int value, int index) {
        super.setElementAt(new Float(value), index);
    }

    public void setAt(long value, int index) {
        super.setElementAt(new Float(value), index);
    }

    public void setAt(byte value, int index) {
        super.setElementAt(new Float(value), index);
    }

    public void setAt(char value, int index) {
        super.setElementAt(new Float(value), index);
    }

    public void setAt(Object value, int index) {
        super.setElementAt(value, index);
    }

    public float sum() {
        float tot = 0;
        NaNRegisters = 0;
        for (int cont = 0; size() > cont; cont++) {
            if (elementAt(cont) instanceof Float) {
                tot += ((Float) elementAt(cont)).floatValue();
            } else if (elementAt(cont) instanceof Double) {
                tot += ((Double) elementAt(cont)).floatValue();
            } else if (elementAt(cont) instanceof Short) {
                tot += Float.parseFloat(((Short) elementAt(cont)).toString());
            } else if (elementAt(cont) instanceof Integer) {
                tot += ((Integer) elementAt(cont)).floatValue();
            } else if (elementAt(cont) instanceof Long) {
                tot += ((Long) elementAt(cont)).floatValue();
            } else if (elementAt(cont) instanceof Byte) {
                tot += Float.parseFloat(((Byte) elementAt(cont)).toString());
            } else if (elementAt(cont) instanceof Character) {
                tot += ((Character) elementAt(cont)).charValue();
            } else {
                NaNRegisters++;
            }
        }
        return tot;
    }

    public float avg() {
        float sum = this.sum();
        if ((size() - NaNRegisters) > 0) {
            return (float) (sum / (size() - NaNRegisters));
        }
        return 0.0f;
    }
}
