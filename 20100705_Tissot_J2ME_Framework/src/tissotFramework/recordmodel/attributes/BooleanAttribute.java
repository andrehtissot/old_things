package tissotFramework.recordmodel.attributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class BooleanAttribute extends ModelAttribute {

    protected Boolean value;

    public BooleanAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, Boolean.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(Boolean b) {
        this.value = b;
    }

    public void setValue(boolean b) {
        this.value = (b ? Boolean.TRUE : Boolean.FALSE);
    }

    public Boolean getBooleanValue() {
        return this.value;
    }

    public boolean getPrimitiveValue() {
        return this.value.booleanValue();
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeBoolean(this.value.booleanValue());
    }

    public void readOnStream(DataInputStream is) throws IOException {
        this.value = new Boolean(is.readBoolean());
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        return is.readBoolean() == this.value.booleanValue();
    }
}
