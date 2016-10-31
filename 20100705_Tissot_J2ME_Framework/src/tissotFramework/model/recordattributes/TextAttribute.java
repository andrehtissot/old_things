package tissotFramework.model.recordattributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public class TextAttribute extends ModelAttribute {

    protected String value;

    public TextAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, Boolean.class);
    }

    public boolean isSet() {
        return (this.value != null);
    }

    public void setValue(String s) {
        this.value = s;
    }

    public String getValue() {
        return this.value;
    }

    public String toString(){
        if(this.value == null)
            return "";
        return this.value;
    }

    public void writeOnStream(DataOutputStream os) throws IOException {
        os.writeInt(this.value.length());
        os.writeChars(value);
//        os.writeUTF(this.value);
    }

    public void readOnStream(DataInputStream is) throws IOException {
        int lenght = is.readInt();
        byte[] bytes = {};
        is.read(bytes, 4, lenght+4);
        this.value = String.valueOf(bytes);
//        this.value = is.readUTF();
    }

    public boolean compareFromStream(DataInputStream is) throws IOException {
        int lenght = is.readInt();
        byte[] bytes = {};
        is.read(bytes, 4, lenght+4);
        return this.value.equals(String.valueOf(bytes));
//        return is.readUTF().equals(this.value);
    }
}
