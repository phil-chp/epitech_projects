const express = require('express');
var request = require('supertest');


describe('HealthCheck', function() {
    const app = express();

    before(function(done) {
        const HealthCheckTest = require("./../../api/HealthCheck.ts")

        app.use("/ping", HealthCheckTest)
        app.listen(function(err: any) {
            if (err) { return done(err); }
            done();
        });
    });

    it('HealthCheckTest Basic', function() {
        request(app)
            .get('/ping')
            .expect(200);
    });
});
