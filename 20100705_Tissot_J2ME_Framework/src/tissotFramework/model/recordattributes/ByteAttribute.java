package tissotFramework.model.recordattributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class ByteAttribute extends ModelAttribute {

    protected Byte value;

    public ByteAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, ByteAttribute.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(Byte b) {
        this.value = b;
    }

    public void setValue(byte b) {
        this.value = new Byte(b);
    }

    public String toString(){
        return this.value.toString();
    }

    public Byte getByteValue() {
        return this.value;
    }

    public byte getPrimitiveValue() {
        return this.value.byteValue();
    }

    public void readOnStream(DataInputStream is) throws IOException {
        this.value = new Byte(is.readByte());
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        return is.readByte() == this.value.byteValue();
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeByte(this.value.byteValue());
    }
}
