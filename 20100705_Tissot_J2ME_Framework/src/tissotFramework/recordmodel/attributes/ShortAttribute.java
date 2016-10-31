package tissotFramework.recordmodel.attributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class ShortAttribute extends ModelAttribute {

    protected Short value;

    public ShortAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, Integer.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(Short s) {
        this.value = s;
    }

    public void setValue(short s) {
        this.value = new Short(s);
    }

    public Short getShortValue() {
        return this.value;
    }

    public short getPrimitiveValue() {
        return this.value.shortValue();
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeShort(this.value.shortValue());
    }

    public void readOnStream(DataInputStream is) throws IOException {
        this.value = new Short(is.readShort());
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        return is.readShort() == this.value.shortValue();
    }
}
