package tissotFramework.model.recordattributes;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;
import javax.microedition.rms.RecordStoreException;
import javax.microedition.rms.RecordStoreFullException;
import javax.microedition.rms.RecordStoreNotFoundException;
import tissotFramework.model.ModelAttribute;
import tissotFramework.model.RecordStoreModel;

/** @author André Augusto Tissot */
public abstract class RelationAttribute extends ModelAttribute {

    protected RecordStoreModel object;

    public RelationAttribute(RecordStoreModel model, String attributeName) {
        super(model, attributeName, RecordStoreModel.class);
    }

    public boolean isSet() {
        return (this.object != null);
    }

    public String toString(){
        return this.object.getModelName();
    }

    public void setRelationed(RecordStoreModel r) {
        this.object = r;
    }

    public RecordStoreModel getRelationed() {
        return this.object;
    }

    public void writeOnStream(DataOutputStream os) throws IOException, RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException {
        this.object.save();
    }

    public void readOnStream(DataInputStream is) throws IOException, RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException {
        this.object.reload();
    }

    public boolean compareFromStream(DataInputStream is) throws IOException, RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException {
        return this.object.hasChanged();
    }
}
