package tissotFramework.model.recordattributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class DoubleAttribute extends ModelAttribute {

    protected Double value;

    public DoubleAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, Double.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(Double d) {
        this.value = d;
    }

    public void setValue(double d) {
        this.value = new Double(d);
    }

    public String toString(){
        return this.value.toString();
    }

    public Double getDoubleValue() {
        return this.value;
    }

    public double getPrimitiveValue() {
        return this.value.doubleValue();
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeDouble(this.value.doubleValue());
    }

    public void readOnStream(DataInputStream is) throws IOException {
        this.value = new Double(is.readDouble());
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        return is.readDouble() == this.value.doubleValue();
    }
}
