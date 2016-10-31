package tissotFramework.model;

import java.io.IOException;
import java.util.Enumeration;
import javax.microedition.rms.RecordStore;
import javax.microedition.rms.RecordStoreException;
import javax.microedition.rms.RecordStoreFullException;
import javax.microedition.rms.RecordStoreNotFoundException;
import tissotFramework.core.Config;
import tissotFramework.util.RestrictedHashtable;
import tissotFramework.util.Validations;

/** @author André Augusto Tissot */
public abstract class RecordStoreModel extends Model {

    private int id = 0;
    private String modelName;
    RestrictedHashtable fields = new RestrictedHashtable(String.class, ModelAttribute.class);

    public int getId() {
        return this.id;
    }

    public String getModelName() {
        return modelName;
    }

    public void RecordStoreModel(String modelName) throws IllegalArgumentException {
        if (Validations.haveSpecialCharacters(modelName)) {
            throw new IllegalArgumentException("modelName don't accept special characteres!");
        }
        if (Validations.haveSpecialCharacters(Config.PROJECT_NAME)) {
            throw new IllegalArgumentException("The project name don't accept special characteres!");
        }
        this.modelName = modelName;
    }

    public void RecordStoreModel(String modelName, int id) throws IllegalArgumentException, RecordStoreFullException, RecordStoreException, RecordStoreNotFoundException, IOException {
        if (Validations.haveSpecialCharacters(modelName)) {
            throw new IllegalArgumentException("modelName don't accept special characteres!");
        }
        if (Validations.haveSpecialCharacters(Config.PROJECT_NAME)) {
            throw new IllegalArgumentException("The project name don't accept special characteres!");
        }
        this.modelName = modelName;
        this.id = id;
        this.reload();
    }

    public RestrictedHashtable getFields() {
        return this.fields;
    }

    public boolean isANewRecord() {
        return (id == 0);
    }

    public int generateId() throws RecordStoreFullException, RecordStoreException {
        int i = 0;
        try {
            RecordStore rs = RecordStore.openRecordStore(modelName, false);
            byte[] b;
            do {
                i++;
                b = rs.getRecord(i);
            } while (b.length > 0 && b[0] > 0);
            return i;
        } catch (RecordStoreNotFoundException ex) {
            return i;
        }
    }

    public boolean hasChanged() throws RecordStoreFullException, RecordStoreNotFoundException, RecordStoreException, IOException {
        if (!this.isANewRecord()) {
            Enumeration e = this.fields.keys();
            while (e.hasMoreElements()) {
                if (((ModelAttribute) e.nextElement()).hasChanged()) {
                    return true;
                }
            }
            return false;
        }
        return true;
    }

    boolean create() throws RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException {
        RecordStore rs = RecordStore.openRecordStore(this.modelName, true);
        if (this.isANewRecord()) {
            this.id = this.generateId();
            rs.setRecord(this.id, (new byte[]{1}), 0, 1);
        }
        rs.closeRecordStore();
        return true;
    }

    public void save() throws RecordStoreNotFoundException, RecordStoreFullException, RecordStoreException, IOException {
        if (this.isANewRecord()) {
            this.create();
        }
        if (this.isANewRecord()) {
            throw new RecordStoreException("Model save error");
        }
        Enumeration e = this.fields.keys();
        while (e.hasMoreElements()) {
            ((ModelAttribute) e.nextElement()).save();
        }
    }

    public void reload() throws RecordStoreFullException, RecordStoreNotFoundException, RecordStoreException, IOException {
        if (!this.isANewRecord()) {
            Enumeration e = this.fields.keys();
            while (e.hasMoreElements()) {
                ((ModelAttribute) e.nextElement()).reload();
            }
        }
    }
}
