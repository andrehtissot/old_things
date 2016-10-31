package tissotFramework.util;

import java.util.Vector;

/** @author André Tissot */
public class RestrictedVector extends Vector {

    private Class type;

    public Class getRestriction() {
        return type;
    }

    public RestrictedVector(Class type) {
        this.type = type;
    }

    public RestrictedVector(Object type) {
        this.type = type.getClass();
    }

    public void add(Object obj) {
        if (type.isInstance(obj)) {
            super.addElement(obj);
        }
    }

    public Object get(int index) {
        return elementAt(index);
    }

    public void addElement(Object obj) {
        if (type.isInstance(obj)) {
            super.addElement(obj);
        }
    }

    public int indexOf(Object obj) {
        if (type.isInstance(obj)) {
            return super.indexOf(obj);
        }
        return -1;
    }

    public int indexOf(Object obj, int index) {
        if (type.isInstance(obj)) {
            return super.indexOf(obj, index);
        }
        return -1;
    }

    public int lastIndexOf(Object obj) {
        if (type.isInstance(obj)) {
            return super.lastIndexOf(obj);
        }
        return -1;
    }

    public int lastIndexOf(Object obj, int index) {
        if (type.isInstance(obj)) {
            return super.lastIndexOf(obj, index);
        }
        return -1;
    }

    public void insertElementAt(Object obj, int index) {
        if (type.isInstance(obj)) {
            super.insertElementAt(obj, index);
        }
    }

    public boolean removeElement(Object obj) {
        if (type.isInstance(obj)) {
            return super.removeElement(obj);
        }
        return false;
    }

    public void setElementAt(Object obj, int index) {
        if (type.isInstance(obj)) {
            super.setElementAt(obj, index);
        }
    }
}
