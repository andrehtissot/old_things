package tissotFramework.model.recordattributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class IntegerAttribute extends ModelAttribute {

    protected Integer value;

    public IntegerAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, Integer.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(Integer i) {
        this.value = i;
    }

    public void setValue(int i) {
        this.value = new Integer(i);
    }

    public String toString(){
        return this.value.toString();
    }

    public Integer getIntegerValue() {
        return this.value;
    }

    public int getPrimitiveValue() {
        return this.value.intValue();
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeInt(this.value.intValue());
    }

    public void readOnStream(DataInputStream is) throws IOException {
        this.value = new Integer(is.readInt());
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        return is.readInt() == this.value.intValue();
    }
}
