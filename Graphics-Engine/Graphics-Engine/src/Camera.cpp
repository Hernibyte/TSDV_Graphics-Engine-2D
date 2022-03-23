#include "Camera.h"

Camera::Camera(Renderer& renderer) {
	render = &renderer;
}

void Camera::SetPosition(float x, float y, float z) {
	render->mvp.cameraPos.x = x;
	render->mvp.cameraPos.y = y;
	render->mvp.cameraPos.z = z;
}

void Camera::Translate(float x, float y, float z) {
	render->mvp.cameraPos.x += x;
	render->mvp.cameraPos.y += y;
	render->mvp.cameraPos.z += z;
}

void Camera::Rotate(float x, float y, bool constrainPitch) {
	render->mvp.yaw += x;
	render->mvp.pitch += y;

	if (constrainPitch) {
		if (render->mvp.pitch > 89.0f)
			render->mvp.pitch = 89.0f;
		if (render->mvp.pitch < -89.0f)
			render->mvp.pitch = -89.0f;
	}

	UpdateCameraVectors();
}

void Camera::UpdateCameraVectors() {
	glm::vec3 front { };
	front.x = cos(glm::radians(render->mvp.yaw) * cos(glm::radians(render->mvp.pitch)));
	front.y = sin(glm::radians(render->mvp.pitch));
	front.z = sin(glm::radians(render->mvp.yaw) * cos(glm::radians(render->mvp.pitch)));
	render->mvp.cameraFront = front;
	render->mvp.cameraRight = glm::normalize(glm::cross(render->mvp.cameraFront, render->mvp.worldUp));
	render->mvp.cameraUp = glm::normalize(glm::cross(render->mvp.cameraRight, render->mvp.cameraFront));
}

void Camera::SetProjection(ProjectionType type) {
	render->projectionType = type;
}