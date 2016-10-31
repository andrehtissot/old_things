package tissotFramework.model;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import tissotFramework.util.Validations;
import javax.microedition.rms.RecordStore;
import javax.microedition.rms.RecordStoreException;
import javax.microedition.rms.RecordStoreFullException;
import javax.microedition.rms.RecordStoreNotFoundException;

/** @author André Augusto Tissot */
public abstract class ModelAttribute {

    protected String attributeName;
    protected RecordStoreModel model;
    protected Class type;

    public ModelAttribute(RecordStoreModel model, String attributeName, Class type) {
        if (Validations.haveSpecialCharacters(attributeName)) {
            throw new IllegalArgumentException("attributeName don't accept special characteres!");
        }
        this.attributeName = attributeName;
        this.type = type;
        if (model instanceof RecordStoreModel) {
            model.fields.add(attributeName, this);
        }
    }

    public String getAttributeName() {
        return this.attributeName;
    }

    public Class getAttributeType() {
        return this.type;
    }

    public boolean equals(Object o) {
        if(o instanceof ModelAttribute){
            ModelAttribute a = (ModelAttribute) o;
            return (this.attributeName.equals(a.attributeName) && this.model.equals(a.model));
        }
        return false;
    }

    public int hashCode() {
        return this.attributeName.length() * 10 + this.model.getModelName().length();
    }

    public abstract boolean isSet();

    public abstract void writeOnStream(DataOutputStream os) throws IOException, RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException;

    public abstract void readOnStream(DataInputStream is) throws IOException, RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException;

    public abstract boolean compareFromStream(DataInputStream is) throws IOException, RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException;

    public boolean hasChanged() throws RecordStoreFullException, RecordStoreNotFoundException, RecordStoreException, IOException {
        if (this.model instanceof RecordStoreModel && !this.model.isANewRecord()) {
            RecordStore rs = RecordStore.openRecordStore(this.model.getModelName() + '_' + this.attributeName, true);
            byte[] data = rs.getRecord(this.model.getId());
            DataInputStream is = new DataInputStream(new ByteArrayInputStream(data));
            boolean changed = compareFromStream(is);
            is.close();
            rs.closeRecordStore();
            return changed;
        }
        return false;
    }

    public boolean reload() throws RecordStoreFullException, RecordStoreNotFoundException, RecordStoreException, IOException {
        if (this.model instanceof RecordStoreModel && !this.model.isANewRecord()) {
            System.out.println("AQUII");
            RecordStore rs = RecordStore.openRecordStore(this.model.getModelName() + '_' + this.attributeName, true);
            byte[] data = rs.getRecord(this.model.getId());
            DataInputStream is = new DataInputStream(new ByteArrayInputStream(data));
            readOnStream(is);
            is.close();
            rs.closeRecordStore();
            return true;
        }
        return false;
    }

    public boolean save() throws RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException, IOException {
        System.out.println("testes");
        System.out.println(this.model instanceof RecordStoreModel);
        System.out.println(this.isSet());
        System.out.println(this.model.create());
        System.out.println(!this.model.isANewRecord());
        if (this.model instanceof RecordStoreModel && this.isSet() && this.model.create() && !this.model.isANewRecord()) {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            DataOutputStream os = new DataOutputStream(baos);
            writeOnStream(os);
            os.close();
            byte[] data = baos.toByteArray();
            RecordStore rs = RecordStore.openRecordStore(this.model.getModelName() + '_' + this.attributeName, true);
            rs.setRecord(this.model.getId(), data, 0, data.length);
            rs.closeRecordStore();
            return true;
        }
        return false;
    }
}
