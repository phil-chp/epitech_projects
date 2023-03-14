import { Request, Response, Router } from 'express';
import { getAllServiceFomUserInDB, addServiceToUserInDB, updateServiceFromUserInDB, deleteServiceFromUserInDB, getServiceFromUserInDB } from '../../services/user';

const router: Router = Router();


router.post('/user/:id/service', async (req, res) => {
    try {
      const service = req.body;

      await addServiceToUserInDB(req.params.id, service);

      res.status(200).json({ message: 'Service '+ service.name +' created successfully' });
        

    } catch (error : any) {
      // Return error
      res.status(401).json({ message: error.message });
    }
});

router.get('/user/:id/services', async (req, res) => {
    try {
        const services = await getAllServiceFomUserInDB(req.params.id);
        res.status(200).json({ service: services.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});


router.get('/user/:id/service/:serviceId', async (req, res) => {
    try {
        const service = await getServiceFromUserInDB(req.params.id, req.params.serviceId);
        res.status(200).json({ service: service.val() });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.put('/user/:id/service/:serviceId', async (req, res) => {
    try {
        const service = req.body;
        await updateServiceFromUserInDB(req.params.id, req.params.serviceId, service);
        res.status(200).json({ message: 'Service'+ service.name +' updated successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});

router.delete('/user/:id/service/:serviceId', async (req, res) => {
    try {
        await deleteServiceFromUserInDB(req.params.id, req.params.serviceId);
        res.status(200).json({ message: 'Service'+ req.params.serviceId +' deleted successfully' });
    } catch (error : any) {
        res.status(401).json({ message: error.message });
    }
});


export const UserService: Router = router;

