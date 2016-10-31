package tissotFramework.model.recordattributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class FloatAttribute extends ModelAttribute {

    protected Float value;

    public FloatAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, Float.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(Float f) {
        this.value = f;
    }

    public String toString(){
        return this.value.toString();
    }

    public void setValue(float f) {
        this.value = new Float(f);
    }

    public Float getFloatValue() {
        return this.value;
    }

    public float getPrimitiveValue() {
        return this.value.floatValue();
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeFloat(this.value.floatValue());
    }

    public void readOnStream(DataInputStream is) throws IOException {
        this.value = new Float(is.readFloat());
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        return is.readFloat() == this.value.floatValue();
    }
}
