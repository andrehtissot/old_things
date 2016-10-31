package tissotFramework.util;

import java.util.Hashtable;

/** @author André Tissot */
public class RestrictedHashtable extends Hashtable {

    private Class keyType;
    private Class valueType;

    public Class getKeyRestriction() {
        return keyType;
    }

    public Class getValueRestriction() {
        return valueType;
    }

    public RestrictedHashtable(Class keyType, Class valueType) {
        this.keyType = keyType;
        this.valueType = valueType;
    }

    public void add(Object key, Object value) {
        if (keyType.isInstance(key) && valueType.isInstance(value)) {
            super.put(key, value);
        }
    }

    public synchronized Object put(Object key, Object value) {
        if (keyType.isInstance(key) && valueType.isInstance(value)) {
            return super.put(key, value);
        }
        return null;
    }
}
