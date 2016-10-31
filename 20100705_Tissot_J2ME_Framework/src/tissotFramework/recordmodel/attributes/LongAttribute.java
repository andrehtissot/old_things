package tissotFramework.recordmodel.attributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class LongAttribute extends ModelAttribute {

    protected Long value;

    public LongAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, Long.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(Long l) {
        this.value = l;
    }

    public void setValue(long l) {
        this.value = new Long(l);
    }

    public Long getLongValue() {
        return this.value;
    }

    public long getPrimitiveValue() {
        return this.value.longValue();
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeLong(this.value.longValue());
    }

    public void readOnStream(DataInputStream is) throws IOException {
        this.value = new Long(is.readLong());
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        return is.readLong() == this.value.longValue();
    }
}
